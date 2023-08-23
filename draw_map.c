
#include "cubed.h"

void	draw_map_grid(void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= WINDOW_H)
	{
		while (x <= WINDOW_W)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y += UNIT;
		x = 0;
	}
	y = 0;
	while (x <= WINDOW_W)
	{
		while (y <= WINDOW_H)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			y++;
		}
		x += UNIT;
		y = 0;
	}
}

static void	draw_unit_rectangle(t_data *data, int x, int y, int color)
{
	int	x_limiter;
	int	y_limiter;

	y_limiter = y + UNIT;
	x_limiter = x + UNIT;
	while (y <= y_limiter)
	{
		while (x <= x_limiter)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
			x++;
		}
		x -= UNIT;
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
			if (map[y][x] == 1)
				draw_unit_rectangle(data, x * UNIT, y * UNIT, color);
			x++;
		}
		y++;
	}
}