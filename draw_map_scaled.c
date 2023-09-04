
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
t_image *get_hitted_texture(t_vector ray_hit, t_player *player, t_data *data)
{	
	//printf("ray hit")
	if (ray_hit.x != (double)(int)ray_hit.x) // if teilbar durch unit
	{
		if (player->pos.y > ray_hit.y)
			return (data->N_texture);
		else
			return (data->S_texture);
	}
	else// if teilbar durch unit
	{
		if (player->pos.x > ray_hit.x) 
			return (data->W_texture);
		else
			return (data->E_texture);
	}
}

//void set_we_so_walls()
//{
//	
//}

//or normalised width coordinate
double set_texture_and_rel_x_pos(t_vector ray_hit, t_data *data, t_image **texture)
{
	double abs_offset_x_to_map;
	double offset_to_last_unit;

	if (ray_hit.x == (double)(int)ray_hit.x) // if teilbar durch unit
	{
		if (ray_hit.y < 0)
			ray_hit.y *= -1;
		abs_offset_x_to_map = ray_hit.y;
		if (data->player->pos.x > ray_hit.x)
		{
			(*texture) = data->W_texture;
			offset_to_last_unit = UNIT - (lround(abs_offset_x_to_map) % UNIT);
		} 
		else
		{
			(*texture) = data->E_texture;
			offset_to_last_unit = lround(abs_offset_x_to_map) % UNIT;
		}
	}
	else
	{
		if (ray_hit.x < 0)
			ray_hit.x *= -1;
		abs_offset_x_to_map = ray_hit.x;
		if (data->player->pos.y > ray_hit.y)
		{
			(*texture) = data->N_texture;
			offset_to_last_unit = lround(abs_offset_x_to_map) % UNIT;
		}
		else
		{
			(*texture) = data->S_texture;
			offset_to_last_unit = UNIT - (lround(abs_offset_x_to_map) % UNIT);
		}
	}
	return (offset_to_last_unit / UNIT);
}

void draw_texture_scaled(int y_start, int y_end, int x, t_data *data)
{
	t_image *texture;
	double offset_y; 
	double norm_x; 
	double norm_y;
	double wall_h;
	int color;

	//texture = get_hitted_texture(data->player->ray[x].vector, data->player, data);
	norm_x = set_texture_and_rel_x_pos(data->player->ray[x].vector, data, &texture);
	wall_h = UNIT * WINDOW_H / data->player->ray[x].length;
	
	int txt_pxl;
	if (wall_h <= WINDOW_H)
	{
		offset_y = 0;
		while (y_start < y_end)
		{
			norm_y = offset_y / wall_h;
			txt_pxl = lround(norm_y * texture->height) * texture->line_len 
					+ lround(norm_x * texture->line_len);
			color = texture->addr[txt_pxl];
			put_pxl_to_img(data->img, x, y_start, color);
			offset_y++;
			y_start++;
		}
	}
	else
	{
		offset_y = (wall_h - WINDOW_H) / 2;
		while (y_start < y_end)
		{
			norm_y = offset_y / wall_h;
			txt_pxl = lround(norm_y * texture->height) * texture->line_len 
					+ lround(norm_x * texture->line_len);
			color = texture->addr[txt_pxl];
			put_pxl_to_img(data->img, x, y_start, color);
			y_start++;
			offset_y++;
		}
	}
}

/* void draw_texture_scaled2(int y_start, int y_end, int x, t_data *data)
{
	t_image *texture;
	double offset_y; 
	double norm_x; 
	double norm_y;
	double wall_h;
	int color;

	texture = get_hitted_texture(data->player->ray[x].vector, data->player, data);
	norm_x = get_normalised_x_coordinate(data->player->ray[x].vector);
	wall_h = UNIT * WINDOW_H / data->player->ray[x].length;
	
	int txt_pxl;
	if (wall_h <= WINDOW_H)
	{
		offset_y = 0;
		norm_y = texture->height / wall_h; //ratio
		while (y_start < y_end)
		{
			txt_pxl = lround(offset_y * norm_y) * texture->line_len 
					+ lround(norm_x * texture->line_len);
			color = texture->addr[txt_pxl];
			put_pxl_to_img(data->img, x, y_start, color);
			offset_y++;
			y_start++;
		}
	}
	else
	{
		offset_y = (wall_h - WINDOW_H) / 2;
		norm_y = texture->height / wall_h; //ratio
		while (y_start < y_end)
		{
			txt_pxl = lround(offset_y * norm_y) * texture->line_len 
					+ lround(norm_x * texture->line_len);
			color = texture->addr[txt_pxl];
			put_pxl_to_img(data->img, x, y_start, color);
			y_start++;
			offset_y++;
		}
	}
} */


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
	//printf("smth weirrd\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	//draw_map_grid(data->mlx_ptr, data->win_ptr, WHITE);
}
