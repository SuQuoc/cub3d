
#include "cubed.h"

void	draw_player(t_player *player, void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y - 4;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		x -= 9;
		y++; 
	}
}

void	draw_player_camera(t_data *data, t_player *player, int color)
{
	t_vector	right;
	t_vector	left;

	init_vector(&left, player->camera_left.x + player->direction.x + player->pos.x, \
						player->camera_left.y + player->direction.y + player->pos.y);

	init_vector(&right, player->camera_right.x + player->direction.x + player->pos.x,\
						player->camera_right.y + player->direction.y + player->pos.y);
	draw_line(data, left, right, color);
}

void	draw_rays(t_data *data, t_player *player, int color)
{
	t_vector	ray;
	int	x;

	x = 0;
	while (x < RAY_NB)
	{
		ray = vector_addition(player->ray[x], player->pos);
		draw_line(data, player->pos, ray, color);
		x++;
	}
}
