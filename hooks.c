
#include "cubed.h"

int	x_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free_data(data);
	return (0);
}
