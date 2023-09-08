
#include "cubed.h"

double	get_segment_length(double a, double b)
{
	double		length;

	length = a / b;
	length *= length;
	length = sqrt(length + 1);
	return (length);
}

double	get_unit_offset(double pos)
{
	if (pos < 0)
		pos *= -1;
	while (pos > UNIT)
		pos -= UNIT;
	return (pos);
}

int	check_map_position(const t_data *data, t_dda_ray *dda_ray, t_vector *pos, char x_or_y)
{
	int	x;
	int y;

	y = (dda_ray->y + pos->y) / UNIT;
	x = (dda_ray->x + pos->x) / UNIT;

	if (dda_ray->y < 0 && x_or_y == 'y')
		y = (dda_ray->y + pos->y - 1) / UNIT;
	if (dda_ray->x < 0 && x_or_y == 'x')
		x = (dda_ray->x + pos->x - 1) / UNIT;

	if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
		return (1);
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}

void	init_dda_ray(t_dda_ray *dda_ray, double a, double b)
{
	dda_ray->fixed_side = 1;
	dda_ray->length = 0;
	dda_ray->x = 0;
	dda_ray->y = 0;
	if (a == 0)
	{
		dda_ray->variable_side = 0;
		dda_ray->hl = 1;
	}
	else if (b == 0)
	{
		dda_ray->variable_side = 1;
		dda_ray->hl = 0;
		dda_ray->fixed_side = 0;
		if (a < 0 && b == 0)
			dda_ray->variable_side *= -1;
	}
	else
	{
		dda_ray->variable_side = (a) / b;
		dda_ray->hl = get_segment_length(a, b);
	}
	if (b < 0)
	{
		dda_ray->variable_side *= -1;
		dda_ray->fixed_side *= -1;
	}
}
