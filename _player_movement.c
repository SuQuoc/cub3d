
#include "cubed.h"

void	_player_move_right(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->x_pos - 4;
	y = player->y_pos - 4;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos - 3)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 2;
		y++; 
	}
	x = player->x_pos + 5;
	y = player->y_pos - 4;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos + 6)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, RED);
			x++;
		}
		x -= 2;
		y++; 
	}
	player->x_pos += 2;
}

void	_player_move_left(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->x_pos + 3;
	y = player->y_pos - 4;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 2;
		y++; 
	}
	x = player->x_pos - 6;
	y = player->y_pos - 4;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos - 5)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, RED);
			x++;
		}
		x -= 2;
		y++; 
	}
	player->x_pos -= 2;
}

void	_player_move_down(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->x_pos - 4;
	y = player->y_pos - 4;
	while (y <= player->y_pos - 3)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 9;
		y++; 
	}
	x = player->x_pos - 4;
	y = player->y_pos + 5;
	while (y <= player->y_pos + 6)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, RED);
			x++;
		}
		x -= 9;
		y++; 
	}
	player->y_pos += 2;
}

void	_player_move_up(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->x_pos - 4;
	y = player->y_pos + 3;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 9;
		y++; 
	}
	x = player->x_pos - 4;
	y = player->y_pos - 6;
	while (y <= player->y_pos - 5)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, RED);
			x++;
		}
		x -= 9;
		y++; 
	}
	player->y_pos -= 2;
}
