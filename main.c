
#include "cubed.h"

int	make_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (data->win_ptr == NULL)
		free_data(data);
	return (0);
}

void ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_data(data);
}

int main(int argc, char **argv)
{
	t_data *data;
	int fd;

	if (argc != 2)
		return (1);
	fd = check_extension(argv[1]);
	if (fd == -1)
		return (1);
	data = init_data();
	ft_mlx_init(data);	
	loop_file(fd, data);
	make_window(data);

	draw_map_grid(data->mlx_ptr, data->win_ptr, WHITE);
	draw_map_walls(data, data->map, WHITE);
	calculate_rays(data->player, (const char **)data->map);

	//mlx_loop_hook(data->mlx_ptr, &print_x, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_input, data);
	mlx_hook(data->win_ptr, 17, 0, x_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
