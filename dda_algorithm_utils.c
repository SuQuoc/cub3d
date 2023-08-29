
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
	if (pos < 0)
		pos *= -1;
	while (pos > UNIT)
		pos -= UNIT;
	return (pos);
}

int	check_map_position(const t_data *data, t_ray *ray, t_vector *pos)
{
	int	x;
	int y;

	y = (ray->y + pos->y) / UNIT;
	x = (ray->x + pos->x) / UNIT;
	if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
		return (1);
	if (ray->y < 0 || ray->x < 0/*  && (x > 0 || y > 0) */)
	{
		if (ray->y < 0)
			y = (ray->y + pos->y - 1) / UNIT;
		if (ray->x < 0)
			x = (ray->x + pos->x - 1) / UNIT;
		if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
			return (1);
	}
	if (data->map[y][x] == '1')
		return (1);
	return (0);
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
