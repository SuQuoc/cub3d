
#include "cubed.h"

double	get_segment_length(double a, double b)
{
	double		length;

	length = a / b;
	length *= length;
	length = sqrt(length + 1);
	return (length);
}

int	get_multiplicator(int pos)
{
	while (pos > UNIT)
		pos -= UNIT;
	return (pos);
}

void	init_ray(t_ray *ray, double a, double b)
{
	ray->fixed_side = 1;
	ray->length = 0;
	ray->x = 0;
	ray->y = 0;
	if (a == 0)
	{
		ray->variable_side = 0;
		ray->hl = 1;
	}
	else if (b == 0)
	{
		ray->variable_side = 1;
		ray->hl = 1;
		ray->fixed_side = 0;
		if (a < 0 && b == 0)
			ray->variable_side *= -1;
	}
	else
	{
		ray->variable_side = (a) / b;
		ray->hl = get_segment_length(a, b);
	}
	if (b < 0)
	{
		ray->variable_side *= -1;
		ray->fixed_side *= -1;
	}
}
