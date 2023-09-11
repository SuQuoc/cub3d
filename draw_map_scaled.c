
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
		return (draw_black_image(data));
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
