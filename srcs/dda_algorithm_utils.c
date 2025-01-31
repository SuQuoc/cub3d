
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
	while (pos > TILE_SIZE)
		pos -= TILE_SIZE;
	return (pos);
}

int	check_map_position(const t_data *data, t_dda_ray *dda_ray, \
										t_vector *pos, char x_or_y)
{
	int	x;
	int	y;

	y = (dda_ray->y + pos->y) / TILE_SIZE;
	x = (dda_ray->x + pos->x) / TILE_SIZE;
	if (dda_ray->y < 0 && x_or_y == 'y')
		y = (dda_ray->y + pos->y - 1) / TILE_SIZE;
	if (dda_ray->x < 0 && x_or_y == 'x')
		x = (dda_ray->x + pos->x - 1) / TILE_SIZE;
	if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
		return (1);
	if (data->map[y][x] == '1')
		return (1);
	return (0);
}
