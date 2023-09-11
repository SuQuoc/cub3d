
#include "cubed.h"


//testfunctions, prototypes, learning stuff
void	draw_map_grid(void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//while (y <= WINDOW_H)
	//{
	//	while (x <= WINDOW_W)
	//	{
	//		//put_pxl_to_img(data->img, x, y, color);
	//		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
	//		x++;
	//	}
	//	y += TILE_SIZE;
	//	x = 0;
	//}
	y = 0;
	while (x <= WINDOW_W)
	{
		while (y <= WINDOW_H)
		{
			//put_pxl_to_img(data->img, x, y, color);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			y++;
		}
		x += TILE_SIZE;
		y = 0;
	}
}

static void	draw_unit_rectangle(t_data *data, int x, int y, int color)
{
	int	x_limiter;
	int	y_limiter;

	y_limiter = y + TILE_SIZE;
	x_limiter = x + TILE_SIZE;
	while (y <= y_limiter)
	{
		while (x <= x_limiter)
		{
			//put_pxl_to_img(data->img, x, y, color);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x++;
		}
		x -= TILE_SIZE;
		y++; 
	}
}

void	draw_map_walls(t_data *data, char **map, int color)
{
	int	x;
	int y;

	if (!map)
		return ;
	y = 0;
	while (map[y])
	{
		
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_unit_rectangle(data, x * TILE_SIZE, y * TILE_SIZE, color);
			x++;
		}
		y++;
	}
}

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

void color_img_all_colors(t_image *img, int width, int height)
{
	int y;
	int x;
	int color;

	y = 0;
	color = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
	    	img->addr[(y * img->line_len) + x] = color;
			color++; 
			
			x++;
		}
		if (color == 0)
			printf("x = %d\n", x);

		y++;
	}
	printf("V2: line_bytes: %d\n", img->line_len);
	printf("color = %d\n", color);
}

void color_img(t_image *img, int color, int width, int height)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
	    	img->addr[(y * img->line_len) + x] = color;
			x++;
		}
		y++;
	}
}