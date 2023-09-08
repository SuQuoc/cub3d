
#include "cubed.h"

void	draw_vertical_wall(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, WHITE);
		start++;
	}
}

void	draw_vertical_ceiling(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->ceil_color);
		start++;
	}
}

void	draw_vertical_floor(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->floor_color);
		start++;
	}
}

// POINT SAMPLING

// sign = significant
void	set_offset_and_vert_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit)
{
	double	abs_offset_to_map;

	if (ray_hit.y < 0)
		ray_hit.y *= -1;
	abs_offset_to_map = ray_hit.y;
	if (data->player->pos.x < ray_hit.x)
	{
		(*txtr) = data->E_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % TILE_SIZE;
	}
	else
	{
		(*txtr) = data->W_texture;
		(*off_last_unit) = TILE_SIZE - ((int)(abs_offset_to_map) % TILE_SIZE);
	}
}

void	set_offset_and_hori_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit)
{
	double	abs_offset_to_map;

	if (ray_hit.x < 0)
		ray_hit.x *= -1;
	abs_offset_to_map = ray_hit.x;
	if (data->player->pos.y > ray_hit.y)
	{
		(*txtr) = data->N_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % TILE_SIZE;
	}
	else
	{
		(*txtr) = data->S_texture;
		(*off_last_unit) = TILE_SIZE - (int)(abs_offset_to_map) % TILE_SIZE;
	}
}

// or normalised width coordinate
void	set_texture_and_x_pos(t_ray ray, t_data *data, t_image **txtr,
		int *x_in_txtr)
{
	double	offset_to_last_unit;

	if (ray.shorter_ray == 'x')
	{
		set_offset_and_vert_wall_txtr(ray.vector, data, txtr,
			&offset_to_last_unit);
	}
	else
		set_offset_and_hori_wall_txtr(ray.vector, data, txtr,
			&offset_to_last_unit);
	(*x_in_txtr) = (offset_to_last_unit / TILE_SIZE) * (*txtr)->line_len;
	if ((*x_in_txtr) > 0)
		(*x_in_txtr)--;
}

void	set_y_pos_of_texture(int offset_y, int wall_h, t_image *txtr,
		int *y_in_txtr)
{
	double	norm_y;
	int		y;

	norm_y = (double)offset_y / wall_h;
	y = norm_y * txtr->height;
	if (y > 63)
		y--;
	(*y_in_txtr) = (int)y * txtr->line_len;
}

void	draw_texture_scaled(int y_start, int y_end, int x, int ray_x,
		t_data *data)
{
	t_image	*texture;
	int		offset_y;
	int		wall_h;
	int		x_in_txtr;
	int		y_in_txtr;

	set_texture_and_x_pos(data->player->ray[ray_x], data, &texture, &x_in_txtr);
	wall_h = lround(TILE_SIZE * WINDOW_H / data->player->ray[ray_x].length);
	if (wall_h <= WINDOW_H)
		offset_y = 0;
	else
		offset_y = (wall_h - WINDOW_H) / 2;
	while (y_start < y_end)
	{
		set_y_pos_of_texture(offset_y, wall_h, texture, &y_in_txtr);
		put_pxl_to_img(data->img, x, y_start, texture->addr[y_in_txtr
			+ x_in_txtr]);
		offset_y++;
		y_start++;
	}
}

void	draw_black_image(const t_data *data)
{
	int	image_end;
	int	x;

	x = 0;
	image_end = WINDOW_H * WINDOW_W;
	while (x < image_end)
	{
		data->img->addr[x] = BLACK;
		x++;
	}
}

static int	check_if_player_in_wall(const t_data *data)
{
	int	x;
	int	y;

	y = data->player->pos.y / TILE_SIZE;
	x = data->player->pos.x / TILE_SIZE;
	if (y <= 1)
		y = (data->player->pos.y - 1) / TILE_SIZE;
	if (x <= 1)
		x = (data->player->pos.x - 1) / TILE_SIZE;
	if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
		return (1);
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}

void	put_txt_ray_to_image(t_ray *ray, t_data *data)
{
	int		wall_floor;
	int		wall_ceil;
	int		wall_h;
	double	ray_dist;
	int		window_x;
	double	ray_x;

	ray_dist = (double)RAY_NB / (double)WINDOW_W;
	ray_x = 0;
	window_x = 0;
	if (check_if_player_in_wall(data) == 1)
	{
		draw_black_image(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->img_ptr, 0, 0);
		return ;
	}
	while (window_x < WINDOW_W)
	{
		wall_h = lround(TILE_SIZE * WINDOW_H / ray[(int)ray_x].length);
		if (wall_h > WINDOW_H)
			wall_h = WINDOW_H;
		wall_ceil = (WINDOW_H - wall_h) / 2;
		wall_floor = wall_ceil + wall_h;
		if (wall_floor - wall_ceil != wall_h)
			wall_floor++;
		draw_vertical_ceiling(0, wall_ceil, window_x, data);
		draw_texture_scaled(wall_ceil, wall_floor, window_x, (int)ray_x, data);
		draw_vertical_floor(wall_floor, WINDOW_H, window_x, data);
		ray_x += ray_dist;
		window_x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0,
		0);
}
