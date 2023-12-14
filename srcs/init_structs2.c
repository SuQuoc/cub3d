
#include "cubed.h"

void	declare_base_values(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->map_copy = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player = NULL;
	data->img = NULL;
	data->n_texture = NULL;
	data->e_texture = NULL;
	data->s_texture = NULL;
	data->w_texture = NULL;
	data->floor_color = 0;
	data->ceil_color = 0;
	data->err = 0;
	data->cos = cos(PI / 180 * ROTATITON_SPEED);
	data->sin = sin(PI / 180 * ROTATITON_SPEED);
}
