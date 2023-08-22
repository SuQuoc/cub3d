
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

void	rotate_vector_clockwise(t_vector *fp_vector, t_vector *vector)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = fp_vector->x;
	old_y = fp_vector->y;
	new_x = ((COS_1 * old_x) - (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	fp_vector->x = new_x;
	fp_vector->y = new_y;

	vector->x = new_x / POINT_SHIFTER;
	vector->y = new_y / POINT_SHIFTER;
}

void	rotate_vector_counter_clockwise(t_vector *fp_vector, t_vector *vector)
{
	long int	new_x;
	long int	new_y;
	long int	old_x;
	long int	old_y;

	old_x = fp_vector->x;
	old_y = fp_vector->y;
	new_x = ((COS_1 * old_x) + (SIN_1 * old_y)) / POINT_SHIFTER;
	new_y = ((-SIN_1 * old_x) + (COS_1 * old_y)) / POINT_SHIFTER;
	fp_vector->x = new_x;
	fp_vector->y = new_y;

	vector->x = new_x / POINT_SHIFTER;
	vector->y = new_y / POINT_SHIFTER;
}
