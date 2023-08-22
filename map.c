
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
