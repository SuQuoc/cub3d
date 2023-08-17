
#include "cubed.h"

void	draw_player(t_player *player, void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	x = player->pos.x - 4;
	y = player->pos.y - 4;
	while (y <= player->pos.y + 4)
	{
		while (x <= player->pos.x + 4)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, RED);
			x++;
		}
		x -= 9;
		y++; 
	}
}

void	draw_player_camera(t_data *data, t_player *player, int color)
{
	t_vector	right;
	t_vector	left;

	init_vector(&left, player->camera_left.x + player->direction.x, player->camera_left.y + player->direction.y);
	init_vector(&right, player->camera_right.x + player->direction.x, player->camera_right.y + player->direction.y);
	draw_line(data, &left, &right, color);
}

void	rotate_player_direction_clockwise(t_player *player)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

//	player->camera_left = vector_subtraction(player->camera_left, player->direction);
//	player->camera_right = vector_subtraction(player->camera_right, player->direction);
//	ft_printf("camera_left: x: %i	y: %i\ncamera_right: x: %i	y: %i\n\n", player->camera_left.x, player->camera_left.y, player->camera_right.x, player->camera_right.y);

	old_x = player->fixed_point_direction.x;
	old_y = player->fixed_point_direction.y;
	new_x = ((COS_1 * old_x) - (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	player->fixed_point_direction.x = new_x;
	player->fixed_point_direction.y = new_y;

	player->direction.x = (new_x / POINT_SHIFTER) + player->pos.x;
	player->direction.y = (new_y / POINT_SHIFTER) + player->pos.y;
//	player->camera_left = vector_subtraction(player->direction, player->camera_left);
//	player->camera_right = vector_addition(player->direction, player->camera_right);
}

void	rotate_player_direction_counter_clockwise(t_player *player)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

//	player->camera_left = vector_subtraction(player->camera_left, player->direction);
//	player->camera_right = vector_subtraction(player->camera_right, player->direction);

	old_x = player->fixed_point_direction.x;
	old_y = player->fixed_point_direction.y;
	new_x = ((COS_1 * old_x) + (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((-SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	player->fixed_point_direction.x = new_x;
	player->fixed_point_direction.y = new_y;

	player->direction.x = (new_x / POINT_SHIFTER) + player->pos.x;
	player->direction.y = (new_y / POINT_SHIFTER) + player->pos.y;
//	player->camera_left = vector_subtraction(player->direction, player->camera_left);
//	player->camera_right = vector_addition(player->direction, player->camera_right);
}