
#include "cubed.h"

t_player	*init_player(int x_position, int y_position)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x_pos = x_position;
	player->y_pos = y_position;
	return (player);
}

void	draw_player(t_data *data, t_player *player)
{
	int	x;
	int	y;

	x = player->x_pos - 4;
	y = player->y_pos - 4;
	while (y <= player->y_pos + 4)
	{
		while (x <= player->x_pos + 4)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, RED);
			x++;
		}
		x -= 9;
		y++; 
	}
}