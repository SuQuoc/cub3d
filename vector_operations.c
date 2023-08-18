
#include "cubed.h"

t_vector	vector_addition(t_vector first_addend, t_vector second_addend)
{
	t_vector    sum;

	init_vector(&sum, first_addend.x + second_addend.x, \
					first_addend.y + second_addend.y);
	return (sum);
}

t_vector	vector_subtraction(t_vector minuend, t_vector subtrahend)
{
	t_vector    difference;

	init_vector(&difference, minuend.x - subtrahend.x, \
					minuend.y - subtrahend.y);
	ft_printf("minuend: x: %i	y: %i\n", minuend.x, minuend.y);
	ft_printf("subtrahend: x: %i	y: %i\n", subtrahend.x, subtrahend.y);
	ft_printf("difference: x: %i	y: %i\n\n", difference.x, difference.y);
	return (difference);
}

//fp stands for fixed point
static t_vector	calculate_camera_vector(const t_vector fp_camera, int numerator)
{
	t_vector	result;
	long long int	x;
	long long int	y;

	ft_printf("camera:	x: %i y: %i\n", fp_camera.x / POINT_SHIFTER, fp_camera.y / POINT_SHIFTER);
	ft_printf("fp_camera:	x: %i y: %i\n", fp_camera.x, fp_camera.y);
	x = fp_camera.x * numerator / 10 / POINT_SHIFTER;
	y = fp_camera.y * numerator / 10 / POINT_SHIFTER;
	init_vector(&result, x, y);
	ft_printf("numerator: %i	x: %i y: %i\n", numerator, result.x, result.y);
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
	ft_printf("direction: %i	x: %i y: %i\n", numerator, direction.x, direction.y);
	while (x < 10)
	{
		player->ray[x] = vector_addition(direction, \
					calculate_camera_vector(player->fixed_point_camera_left, numerator));
		numerator--;
		x++;
	}
	while (x < 21)
	{
		player->ray[x] = vector_addition(direction, \
					calculate_camera_vector(player->fixed_point_camera_right, numerator));
		numerator++;
		x++;
	}


	int i = 0;
	while (i < 21)
	{
		ft_printf("ray: %i	x: %i y: %i\n", i, player->ray[i].x, player->ray[i].y);
		i++;
	}
	


}
