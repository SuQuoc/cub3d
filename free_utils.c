
#include "cubed.h"

void	free_2d_array(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}



void free_data(t_data *data, int exit_code)
{
	if (!data)
		exit(exit_code);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_2d_array(data->map);
	free(data);
	data = NULL;
	exit(exit_code);
}
