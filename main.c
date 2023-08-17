
#include "cubed.h"

int	make_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_data(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (data->win_ptr == NULL)
		free_data(data);
	return (0);
}

int	x_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free_data(data);
	return (0);
}

int	key_input(int keysym, t_data *data)
{
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Down || keysym == XK_Up)
	{
		draw_line(data, &data->player->pos, &data->player->direction, BLACK);
		if (keysym == XK_Right)
			player_move_right(data->player, data->mlx_ptr, data->win_ptr);
		if (keysym == XK_Left)
			player_move_left(data->player, data->mlx_ptr, data->win_ptr);
		if (keysym == XK_Down)
			player_move_down(data->player, data->mlx_ptr, data->win_ptr);
		if (keysym == XK_Up)
			player_move_up(data->player, data->mlx_ptr, data->win_ptr);
		draw_line(data, &data->player->pos, &data->player->direction, WHITE);
	}


	if (keysym == XK_d || keysym == XK_D || keysym == XK_a || keysym == XK_A)
	{
		draw_line(data, &data->player->pos, &data->player->direction, BLACK);
		if (keysym == XK_d || keysym == XK_D)
			rotate_player_direction_clockwise(data->player);
		if (keysym == XK_a || keysym == XK_A)
			rotate_player_direction_counter_clockwise(data->player);
		draw_player(data->player, data->mlx_ptr, data->win_ptr);
		draw_line(data, &data->player->pos, &data->player->direction, WHITE);
	}


	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free_data(data);
	}
	return (0);
}

int	print_x(t_data *data)
{
	(void)data;
	//draw_line(data, &data->player->pos, &data->player->direction, WHITE);
	return (0);
}

int main(int argc, char **argv)
{
	t_data *data;
	int fd;

	data = init_data();
	if (argc != 2)
		return (1);
	if (check_extension(argv[1]) == 1)
		return (1);
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	
	make_window(data);
	
	data->txt_h = 50;
	data->txt_w = 50;
	loop_file(fd, data);
	ft_putstr_fd("finished check!\n", 2);


	mlx_loop_hook(data->mlx_ptr, &print_x, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_input, data);
	mlx_hook(data->win_ptr, 17, 0, x_window, data);
	
	mlx_loop_hook(data->mlx_ptr, &print_x, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_input, data);
	mlx_hook(data->win_ptr, 17, 0, x_window, data);
	
	mlx_loop(data->mlx_ptr);
	return (0);
}
