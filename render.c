
#include "cubed.h"

int	print_x(t_data *data)
{
	t_point *point;

	point = init_point(10, 10, 10, 10);
	if (!point)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free_data(data);
	}
	draw_line(data, point);
	free(point);
	return (0);
}