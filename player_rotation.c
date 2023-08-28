
#include "cubed.h"

void	calculate_move_values(t_player *player, int x, int y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
	{
		player->fast_axis = 'x';
		player->fault = x / 2;
		player->fast_diff = x;
		player->slow_diff = y;
	}
	else
	{
		player->fast_axis = 'y';
		player->fault = y / 2;
		player->fast_diff = y;
		player->slow_diff = x;
	}
}

void	rotate_vector_clockwise(t_vector *vector)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	old_x = vector->x;
	old_y = vector->y;
	new_x = ((COS_1 * old_x) - (SIN_1 * old_y));
	new_y = ((SIN_1 * old_x) + (COS_1 * old_y));
	vector->x = new_x;
	vector->y = new_y;

/* 	vector->x = ((COS_1 * vector->x) - (SIN_1 * vector->y)) / POINT_SHIFTER;
	vector->y = ((SIN_1 * vector->x) + (COS_1 * vector->y)) / POINT_SHIFTER; */

}

void	rotate_vector_counter_clockwise(t_vector *vector)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	old_x = vector->x;
	old_y = vector->y;
	new_x = ((COS_1 * old_x) + (SIN_1 * old_y));
	new_y = ((-SIN_1 * old_x) + (COS_1 * old_y));
	vector->x = new_x;
	vector->y = new_y;

/* 	vector->x = ((COS_1 * vector->x) + (SIN_1 * vector->y));
	vector->y = ((-SIN_1 * vector->x) + (COS_1 * vector->y)); */
}
