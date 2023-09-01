
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
	double wall_h = y_end - y_start;
	double x_ratio = (double)((double)(x % UNIT) / (double)UNIT); //x_rel should be from 0 to UNIT
	
	double x_in_txt = x_ratio * (double)data->E_texture->line_len;

	
	//printf("img x: %d\n", x);
	//printf("y_start: %d\n", y_start);
	//printf("y_end: %d\n", y_end);
	printf("rel x pos: %f\n", (double)(x % UNIT));
	printf("x_ratio: %f\n", x_ratio);
	printf("X RATIO: %f\n", (double)(x % UNIT) / UNIT);
	
	//(double)(((double)(x) % (double)(UNIT) / (double)(UNIT)))
	
	//printf("line len: %d\n", data->E_texture->line_len);
	//printf("wall h: %f\n", wall_h);


	double y_ratio;
	int color;
	double i = 0;
	while (y_start < y_end)
	{
		y_ratio = i / wall_h;
		//printf("i: %f\n", i);
		//printf("y_ratio: %f\n", y_ratio);
		//printf("txt addr[%d]\n", (int)(y_ratio * data->E_texture->line_len + x_in_txt));
		color = data->E_texture->addr[(int)(y_ratio * (double)data->E_texture->line_len + x_in_txt)];
		put_pxl_to_img(data->img, x, y_start, color);
		y_start++;
		i++;
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
		draw_vertical_ceiling(0, bg_diff, x, data);//start, end, x, data
		
		//draw_texture(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_texture_scaled(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_vertical_floor(WINDOW_H - bg_diff, WINDOW_H, x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}
