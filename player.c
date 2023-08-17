
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

void	rotate_vector_clockwise(t_vector *fixed_point_vector, t_vector *vector)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = fixed_point_vector->x;
	old_y = fixed_point_vector->y;
	new_x = ((COS_1 * old_x) - (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	fixed_point_vector->x = new_x;
	fixed_point_vector->y = new_y;

	vector->x = new_x / POINT_SHIFTER;
	vector->y = new_y / POINT_SHIFTER;
}

void	rotate_vector_counter_clockwise(t_vector *fixed_point_vector, t_vector *vector)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = fixed_point_vector->x;
	old_y = fixed_point_vector->y;
	new_x = ((COS_1 * old_x) + (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((-SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	fixed_point_vector->x = new_x;
	fixed_point_vector->y = new_y;

	vector->x = new_x / POINT_SHIFTER;
	vector->y = new_y / POINT_SHIFTER;
}

/* void	rotate_player_direction_clockwise(t_player *player)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = player->fixed_point_direction.x;
	old_y = player->fixed_point_direction.y;
	new_x = ((COS_1 * old_x) - (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	player->fixed_point_direction.x = new_x;
	player->fixed_point_direction.y = new_y;

	player->direction.x = (new_x / POINT_SHIFTER) + player->pos.x;
	player->direction.y = (new_y / POINT_SHIFTER) + player->pos.y;
} */

/* void	rotate_player_direction_counter_clockwise(t_player *player)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = player->fixed_point_direction.x;
	old_y = player->fixed_point_direction.y;
	new_x = ((COS_1 * old_x) + (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((-SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	player->fixed_point_direction.x = new_x;
	player->fixed_point_direction.y = new_y;

	player->direction.x = (new_x / POINT_SHIFTER) + player->pos.x;
	player->direction.y = (new_y / POINT_SHIFTER) + player->pos.y;
} */