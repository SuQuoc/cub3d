
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
	if (check_extension(argv[1]) == 1)
		return (1);
	data = init_data();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	ft_mlx_init(data);	
	loop_file(fd, data);
	make_window(data);
	//mlx_loop_hook(data->mlx_ptr, &print_x, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_input, data);
	mlx_hook(data->win_ptr, 17, 0, x_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
