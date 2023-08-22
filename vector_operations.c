
#include "cubed.h"

t_vector	vector_multiplication(t_vector vector, int multiplier)
{
	t_vector	product;

	init_vector(&product, vector.x * multiplier, \
					vector.y * multiplier);
	return (product);
}

t_vector	vector_addition(t_vector first_addend, t_vector second_addend)
{
	t_vector	sum;

	init_vector(&sum, first_addend.x + second_addend.x, \
					first_addend.y + second_addend.y);
	return (sum);
}

t_vector	vector_subtraction(t_vector minuend, t_vector subtrahend)
{
	t_vector	difference;

	init_vector(&difference, minuend.x - subtrahend.x, \
					minuend.y - subtrahend.y);
	return (difference);
}

//fp stands for fixed point
static t_vector	calculate_camera_vector(const t_vector fp_camera, int numerator)
{
	t_vector	result;
	long long int	x;
	long long int	y;

	x = fp_camera.x * numerator / 10 / POINT_SHIFTER;
	y = fp_camera.y * numerator / 10 / POINT_SHIFTER;
	init_vector(&result, x, y);
	return (result);
}

void	calculate_rays(t_player	*player)
{
	t_vector	direction;
	int	numerator;
	int	x;

	x = 0;
	numerator = 10;
	direction = vector_subtraction(player->direction, player->pos);
	while (x < 10)
	{
		player->ray[x] = vector_addition(direction, \
					calculate_camera_vector(player->fp_camera_left, numerator));
		player->ray[x] = vector_multiplication(player->ray[x], 2);
		numerator--;
		x++;
	}
	while (x < 21)
	{
		player->ray[x] = vector_addition(direction, \
					calculate_camera_vector(player->fp_camera_right, numerator));
		player->ray[x] = vector_multiplication(player->ray[x], 2);
		numerator++;
		x++;
	}
}
