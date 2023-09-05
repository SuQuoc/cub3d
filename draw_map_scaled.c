
#include "cubed.h"

void draw_vertical_ceiling(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->ceil_color);
		start++;
	}
}

void draw_vertical_floor(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->floor_color);
		start++;
	}
}

//POINT SAMPLING

// sign = significant
void set_offset_and_vert_wall_txtr(t_vector ray_hit, t_data *data, t_image **txtr, double *off_last_unit)
{
	double abs_offset_to_map;

	if (ray_hit.y < 0)
		ray_hit.y *= -1;
	abs_offset_to_map = ray_hit.y;
	if (data->player->pos.x < ray_hit.x)
	{
		(*txtr) = data->E_texture;
		(*off_last_unit) = lround(abs_offset_to_map) % UNIT;
	}
	else
	{
		(*txtr) = data->W_texture;
		(*off_last_unit) = UNIT - (lround(abs_offset_to_map) % UNIT);
	}
}

void set_offset_and_hori_wall_txtr(t_vector ray_hit, t_data *data, t_image **txtr, double *off_last_unit)
{
	double abs_offset_to_map;

	if (ray_hit.x < 0)
		ray_hit.x *= -1;
	abs_offset_to_map = ray_hit.x;
	if (data->player->pos.y > ray_hit.y)
	{
		(*txtr) = data->N_texture;
		(*off_last_unit) = lround(abs_offset_to_map) % UNIT;
	}
	else
	{
		(*txtr) = data->S_texture;
		(*off_last_unit) = UNIT - (lround(abs_offset_to_map) % UNIT);
	}
}

//or normalised width coordinate
void set_texture_and_x_pos(t_vector ray_hit, t_data *data, t_image **txtr, int *x_in_txtr)
{
	double offset_to_last_unit;

	if (ray_hit.x == (double)(int)ray_hit.x) // if teilbar durch unit
	{
		set_offset_and_vert_wall_txtr(ray_hit, data, txtr, &offset_to_last_unit);
	}
	else
	{
		set_offset_and_hori_wall_txtr(ray_hit, data, txtr, &offset_to_last_unit);
	}
	(*x_in_txtr) = offset_to_last_unit / UNIT * (*txtr)->line_len;
}

void set_y_pos_of_texture(double offset_y, double wall_h, int img_height, int *y)
{
	double norm_y;

	norm_y = offset_y / wall_h;
	(*y) = lround(norm_y * img_height) * img_height;
}

void draw_texture_scaled(int y_start, int y_end, int x, t_data *data)
{
	t_image *texture;
	double offset_y; 
	double wall_h;
	int x_in_txtr;
	int y_in_txtr;
	
	set_texture_and_x_pos(data->player->ray[x].vector, data, &texture, &x_in_txtr);
	wall_h = UNIT * WINDOW_H / data->player->ray[x].length;
	if (wall_h <= WINDOW_H)
		offset_y = 0;
	else
		offset_y = (wall_h - WINDOW_H) / 2;
	while (y_start < y_end)
	{
		set_y_pos_of_texture(offset_y, wall_h, texture->height, &y_in_txtr);
		put_pxl_to_img(data->img, x, y_start, texture->addr[y_in_txtr + x_in_txtr]);
		offset_y++;
		y_start++;
	}
}


void put_txt_ray_to_image(t_ray *ray, t_data *data)
{
	double bg_diff;
	double wall_h;
	int x;

	x = 0;
	while (x < RAY_NB)
	{
		wall_h = UNIT * WINDOW_H / ray[x].length;
		if (wall_h > WINDOW_H)
			wall_h = WINDOW_H;
		bg_diff = (WINDOW_H - wall_h) / 2;
		draw_vertical_ceiling(0, bg_diff, x, data);
		draw_texture_scaled(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_vertical_floor(WINDOW_H - bg_diff, WINDOW_H, x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}
