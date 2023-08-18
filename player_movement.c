
#include "cubed.h"

void	player_move_right(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y - 4;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x - 3)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 2;
		y++; 
	}
	player->pos.x += 2;
	player->direction.x += 2;
	draw_player(player, mlx_ptr, win_ptr);
}

void	player_move_left(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->pos.x + 3;
	y = player->pos.y - 4;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 2;
		y++; 
	}
	player->pos.x -= 2;
	player->direction.x -= 2;
	draw_player(player, mlx_ptr, win_ptr);
}

void	player_move_down(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y - 4;
	while (y <= player->pos.y - 3)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 9;
		y++; 
	}
	player->pos.y += 2;
	player->direction.y += 2;
	draw_player(player, mlx_ptr, win_ptr);
}

void	player_move_up(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y + 3;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, BLACK);
			x++;
		}
		x -= 9;
		y++; 
	}
	player->pos.y -= 2;
	player->direction.y -= 2;
	draw_player(player, mlx_ptr, win_ptr);
}
