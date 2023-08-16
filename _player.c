
#include "cubed.h"

void	_draw_player(t_data *data, t_player *player)
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