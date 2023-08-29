
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

void	rotate_vector_clockwise(t_vector *vector, double cos, double sin)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	old_x = vector->x;
	old_y = vector->y;
	new_x = ((cos * old_x) - (sin * old_y));
	new_y = ((sin * old_x) + (cos * old_y));
	vector->x = new_x;
	vector->y = new_y;
}

void	rotate_vector_counter_clockwise(t_vector *vector, double cos, double sin)
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;

	old_x = vector->x;
	old_y = vector->y;
	new_x = ((cos * old_x) + (sin * old_y));
	new_y = ((-sin * old_x) + (cos * old_y));
	vector->x = new_x;
	vector->y = new_y;
}
