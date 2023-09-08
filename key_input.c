
#include "cubed.h"

static void	movement(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		player_move_forward(data->player, data->mlx_ptr, data->win_ptr);
	else if (keysym == XK_s || keysym == XK_S)
		player_move_back(data->player, data->mlx_ptr, data->win_ptr);
	else if (keysym == XK_d || keysym == XK_D)
		player_move_right(data->player, data->mlx_ptr, data->win_ptr);
	else if (keysym == XK_a || keysym == XK_A)
		player_move_left(data->player, data->mlx_ptr, data->win_ptr);
	calculate_rays(data, data->player);
	put_txt_ray_to_image(data->player->ray, data);
}

static void	rotate_player_direction(int keysym, t_data *data)
{
	if (keysym == XK_Right)
	{
		rotate_vector_clockwise(&data->player->direction, data->cos, data->sin);
		rotate_vector_clockwise(&data->player->camera_left, data->cos,
			data->sin);
		rotate_vector_clockwise(&data->player->camera_right, data->cos,
			data->sin);
	}
	else if (keysym == XK_Left)
	{
		rotate_vector_counter_clockwise(&data->player->direction, data->cos,
			data->sin);
		rotate_vector_counter_clockwise(&data->player->camera_left, data->cos,
			data->sin);
		rotate_vector_counter_clockwise(&data->player->camera_right, data->cos,
			data->sin);
	}
	calculate_rays(data, data->player);
	calculate_move_values(data->player, data->player->direction.x,
		data->player->direction.y);
	put_txt_ray_to_image(data->player->ray, data);
}

int	key_input(int keysym, t_data *data)
{
	if (keysym == XK_s || keysym == XK_S || keysym == XK_w || keysym == XK_W
		|| keysym == XK_d || keysym == XK_D || keysym == XK_a || keysym == XK_A)
		movement(keysym, data);
	else if (keysym == XK_Right || keysym == XK_Left)
		rotate_player_direction(keysym, data);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free_data(data);
	}
	return (0);
}
