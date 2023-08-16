
#include "cubed.h"

void	draw_player(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y - 4;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, RED);
			x++;
		}
		x -= 9;
		y++; 
	}
}

void	rotate_player_direction(t_player *player)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = player->direction.x;
	old_y = player->direction.y;
	new_x = ROTATE_X_5 * old_x;
	new_y = ROTATE_Y_5 * old_y;
	player->direction.x = old_x / POINT_SHIFTER;
	player->direction.y = old_y / POINT_SHIFTER;
	
}