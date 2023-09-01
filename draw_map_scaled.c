
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

void draw_texture(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		//printf("pxl x: %d y: %d\n", x, start);
		put_pxl_to_img(data->img, x, start, GREEN);
		start++;
	}
}

//POINT SAMPLING
void draw_texture_scaled(int y_start, int y_end, int x, t_data *data)
{
	int offset; 
	int wall_h;
	double x_ratio; 
	double y_ratio;
	int x_in_txt; 
	int color;
	

	printf("ray hit x: %f\n", data->player->ray[x].x);
	printf("ray hit y: %f\n", data->player->ray[x].x);

	
	offset = lround(data->player->ray[x].x) % UNIT;
	x_ratio = (double)offset / UNIT;
	wall_h = UNIT * WINDOW_H / data->player->ray_length[x];

	int i = 0;
	while (y_start < y_end)
	{
		y_ratio = (double)i / wall_h;
		//printf("y_ratio: %f\n", y_ratio);
		x_in_txt = lround(x_ratio * data->E_texture->line_len);
		color = data->E_texture->addr[lround(y_ratio * data->E_texture->line_len) * data->E_texture->line_len 
			+ x_in_txt];
		put_pxl_to_img(data->img, x, y_start, color);
		y_start++;
		i++;
	}
}

void put_txt_ray_to_image(double *ray_len, t_data *data)
{
	double bg_diff;
	double wall_h;
	int x;

	x = 0;
	while (x < RAY_NB)
	{
		wall_h = UNIT * WINDOW_H / ray_len[x];
		if (wall_h > WINDOW_H)
			wall_h = WINDOW_H;
		bg_diff = (WINDOW_H - wall_h) / 2;
		draw_vertical_ceiling(0, bg_diff, x, data);
		draw_texture_scaled(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_vertical_floor(WINDOW_H - bg_diff, WINDOW_H, x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	//draw_map_grid(data->mlx_ptr, data->win_ptr, WHITE);
}
