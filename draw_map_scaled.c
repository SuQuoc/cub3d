
#include "cubed.h"


void draw_texture_test(int start, int end, int x, t_data *data)
{
	int i = 4106;
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->S_texture->addr[i]);
		//i++;
		start++;
	}
}

void draw_vertical_wall(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, WHITE);
		start++;
	}
}

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
	//printf("ray_hit x or y coord: %f\n", abs_offset_to_map);
	if (data->player->pos.x < ray_hit.x)
	{
		(*txtr) = data->E_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % UNIT;
	}
	else
	{
		(*txtr) = data->W_texture;
		(*off_last_unit) = UNIT - ((int)(abs_offset_to_map) % UNIT);
	}
}

void set_offset_and_hori_wall_txtr(t_vector ray_hit, t_data *data, t_image **txtr, double *off_last_unit)
{
	double abs_offset_to_map;

	if (ray_hit.x < 0)
		ray_hit.x *= -1;
	abs_offset_to_map = ray_hit.x;
	//printf("ray_hit x or y coord: %f\n", abs_offset_to_map);
	if (data->player->pos.y > ray_hit.y)
	{
		(*txtr) = data->N_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % UNIT;
	}
	else
	{
		(*txtr) = data->S_texture;
		(*off_last_unit) = UNIT - (int)(abs_offset_to_map) % UNIT;
	}
}

//or normalised width coordinate
void set_texture_and_x_pos(t_ray ray, t_data *data, t_image **txtr, int *x_in_txtr)
{
	double offset_to_last_unit;

		
	if (ray.shorter_ray == 'x')
	{
		set_offset_and_vert_wall_txtr(ray.vector, data, txtr, &offset_to_last_unit);
	}
	else
		set_offset_and_hori_wall_txtr(ray.vector, data, txtr, &offset_to_last_unit);
	//(*x_in_txtr) = lround((offset_to_last_unit / UNIT) * (*txtr)->line_len); //lround uber ganzes?
	//printf("offset x: %f\n", offset_to_last_unit);
	(*x_in_txtr) = (offset_to_last_unit / UNIT) * (*txtr)->line_len;
	
	if ((*x_in_txtr) > 0)
		(*x_in_txtr)--;
}

void set_y_pos_of_texture(int offset_y, int wall_h, t_image *txtr, int *y_in_txtr)
{
	double norm_y;
	int y;
	norm_y = (double)offset_y / wall_h;
	//printf("norm_y: %f\n", norm_y);
	
	y = norm_y * txtr->height;
//	printf("y: %d\n", y);
	if (y > 63)
		y--;
//	y++;
/* 	if (y > 0)
		y -= 1; */

	//if (y > 60)
	//{
	//	printf("offset_y: %d\n", offset_y);
	//	printf("wall_h: %f\n", wall_h);
	//	printf("norm_y: %f\n", norm_y);
	//	//	printf("norm_y: %f\n", norm_y);
	//	printf("y: %d\n", y);
	//}
	(*y_in_txtr) = (int)y * txtr->line_len;
	//if ((*y_in_txtr) >= 0)
	//	printf("y_in_txtr in textr: %d\n", (*y_in_txtr) / 64);
}

void draw_texture_scaled(int y_start, int y_end, int x, t_data *data)
{
	t_image *texture;
	int offset_y; 
	int wall_h;
	int x_in_txtr;
	int y_in_txtr;
	
	set_texture_and_x_pos(data->player->ray[x], data, &texture, &x_in_txtr);
	wall_h = lround(UNIT * WINDOW_H / data->player->ray[x].length);
	if (wall_h <= WINDOW_H)
		offset_y = 0;
	else
		offset_y = (wall_h - WINDOW_H) / 2;
	//printf("ray len: %f\n", data->player->ray[x].length);
	//int bg_diff = (WINDOW_H - wall_h) / 2;
	//printf("start_y: %i\n", y_end - y_start);
	while (y_start < y_end)
	{
		set_y_pos_of_texture(offset_y, wall_h, texture, &y_in_txtr);
		//if (y_in_txtr + x_in_txtr == 0)
		//	printf("index of txtr: %d\n", y_in_txtr + x_in_txtr);
		//if (y_in_txtr + x_in_txtr > 4090 || offset_y > wall_h)
		//{
		//	//printf("window pos y: %d, x: %d\n", y_start, x);
		//	printf("index of txtr: %d\n", y_in_txtr + x_in_txtr);
		//	printf("offset y: %d\n", offset_y);
		//	printf("wall h: %d\n", wall_h);
		//	printf("\n");
		//	//printf("y: %d, x: %d\n\n", y_in_txtr, x_in_txtr);			
		//}
		put_pxl_to_img(data->img, x, y_start, texture->addr[y_in_txtr + x_in_txtr]);
		//printf("start_y: %i\noffset_y: %i\n\n", y_start - bg_diff, offset_y);
		offset_y++;
		y_start++;
	}
	//printf("offset y: %d\n", offset_y);

}

void put_txt_ray_to_image(t_ray *ray, t_data *data)
{
	int wall_floor;
	int wall_ceil;
	int wall_h;
	int x;

	x = 0;
	while (x < RAY_NB)
	{
		wall_h = lround(UNIT * WINDOW_H / ray[x].length);
		if (wall_h > WINDOW_H)
			wall_h = WINDOW_H;
		wall_ceil = (WINDOW_H - wall_h) / 2;
		wall_floor = wall_ceil + wall_h;
		if (wall_floor - wall_ceil != wall_h)
			wall_floor++;
		draw_vertical_ceiling(0, wall_ceil, x, data);
		//draw_texture_test(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_texture_scaled(wall_ceil, wall_floor, x, data);
		draw_vertical_floor(wall_floor, WINDOW_H, x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}
