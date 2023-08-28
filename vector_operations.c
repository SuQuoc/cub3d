
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
static t_vector	calculate_camera_vector(const t_vector camera, const t_vector direction, int numerator)
{
	t_vector	result;
	double		x;
	double		y;
	int			rn;

	if (RAY_NB <= 1)
		rn = 1;
	else
		rn = RAY_NB / 2;

	x = camera.x * numerator / rn;
	y = camera.y * numerator / rn;	

	x += direction.x;
	y += direction.y;	
	init_vector(&result, x, y);
	return (result);
}

void	calculate_rays(t_player	*player, const char **map)
{
	int	numerator;
	int	x;

	x = 0;
	numerator = (RAY_NB / 2);
	while (x < (RAY_NB / 2))
	{
		player->ray[x] = calculate_camera_vector(player->camera_left, player->direction, numerator);
		player->ray[x] = vector_multiplication(player->ray[x], 2);
	//	dda_algorithm(player, &player->ray[x], map, (long int *)&player->ray_length[x]);

		numerator--;
		x++;
	}
	while (x < RAY_NB)
	{
		player->ray[x] = calculate_camera_vector(player->camera_right, player->direction, numerator);
		player->ray[x] = vector_multiplication(player->ray[x], 2);
	//	dda_algorithm(player, &player->ray[x], map, (long int *)&player->ray_length[x]);

		numerator++;
		x++;
	}
	map++;
	map--;
}
