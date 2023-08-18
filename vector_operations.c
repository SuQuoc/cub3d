
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
