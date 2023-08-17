
#include "cubed.h"

static void	movement(int keysym, t_data *data)
{
	draw_line(data, &data->player->pos, &data->player->direction, BLACK);
	draw_player_camera(data, data->player, BLACK);
	if (keysym == XK_Right)
		player_move_right(data->player, data->mlx_ptr, data->win_ptr);
	if (keysym == XK_Left)
		player_move_left(data->player, data->mlx_ptr, data->win_ptr);
	if (keysym == XK_Down)
		player_move_down(data->player, data->mlx_ptr, data->win_ptr);
	if (keysym == XK_Up)
		player_move_up(data->player, data->mlx_ptr, data->win_ptr);
	draw_line(data, &data->player->pos, &data->player->direction, WHITE);
	draw_player_camera(data, data->player, BLUE);
}

static void	rotate_player_direction(int keysym, t_data *data)
{
	draw_line(data, &data->player->pos, &data->player->direction, BLACK);
	draw_player_camera(data, data->player, BLACK);
	if (keysym == XK_d || keysym == XK_D)
		rotate_player_direction_clockwise(data->player);
	if (keysym == XK_a || keysym == XK_A)
		rotate_player_direction_counter_clockwise(data->player);
	draw_player(data->player, data->mlx_ptr, data->win_ptr);
	draw_line(data, &data->player->pos, &data->player->direction, WHITE);
	draw_player_camera(data, data->player, BLUE);
}

int	key_input(int keysym, t_data *data)
{
	if (keysym == XK_Right || keysym == XK_Left || keysym == XK_Down || keysym == XK_Up)
		movement(keysym, data);

	if (keysym == XK_d || keysym == XK_D || keysym == XK_a || keysym == XK_A)
		rotate_player_direction(keysym, data);

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free_data(data);
	}
	return (0);
}
