
#include "cubed.h"

void	get_y_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, \
														t_vector *pos)
{
	if (dda_ray->hl == 0)
		return ;
	while (1)
	{
		if (check_map_position(data, dda_ray, pos, 'y') != 0)
		{
			return ;
		}
		dda_ray->x += dda_ray->variable_side;
		dda_ray->y += dda_ray->fixed_side;
		dda_ray->length += dda_ray->hl;
	}
}

void	get_x_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, \
														t_vector *pos)
{
	if (dda_ray->hl == 0)
		return ;
	while (1)
	{
		if (check_map_position(data, dda_ray, pos, 'x') != 0)
		{
			return ;
		}
		dda_ray->y += dda_ray->variable_side;
		dda_ray->x += dda_ray->fixed_side;
		dda_ray->length += dda_ray->hl;
	}
}

void	get_x_initial_length(t_dda_ray *dda_ray, double pos_offset)
{
	double	offset;

	if (dda_ray->hl == 0)
		return ;
	if (dda_ray->fixed_side < 0)
		offset = pos_offset;
	else
		offset = (double)TILE_SIZE - pos_offset;
	dda_ray->y += offset * dda_ray->variable_side;
	dda_ray->x += offset * dda_ray->fixed_side;
	dda_ray->length += offset * dda_ray->hl;
	dda_ray->variable_side *= (double)TILE_SIZE;
	dda_ray->fixed_side *= (double)TILE_SIZE;
	dda_ray->hl *= (double)TILE_SIZE;
}

void	get_y_initial_length(t_dda_ray *dda_ray, double pos_offset)
{
	double	offset;

	if (dda_ray->hl == 0)
		return ;
	if (dda_ray->fixed_side < 0)
		offset = pos_offset;
	else
		offset = (double)TILE_SIZE - pos_offset;
	dda_ray->x += offset * dda_ray->variable_side;
	dda_ray->y += offset * dda_ray->fixed_side;
	dda_ray->length += offset * dda_ray->hl;
	dda_ray->variable_side *= (double)TILE_SIZE;
	dda_ray->fixed_side *= (double)TILE_SIZE;
	dda_ray->hl *= (double)TILE_SIZE;
}
