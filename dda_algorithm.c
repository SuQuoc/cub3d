
#include "cubed.h"

void	get_y_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, t_vector *pos)
{
	if (dda_ray->hl == 0)
		return ;

	if (check_map_position(data, dda_ray, pos) == 1)
			return ;
	while (1)
	{
		dda_ray->x += dda_ray->variable_side;
		dda_ray->y += dda_ray->fixed_side;
		dda_ray->length += dda_ray->hl;
		if (check_map_position(data, dda_ray, pos) == 1)
			return ;
	}
}

void	get_x_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, t_vector *pos)
{
	if (dda_ray->hl == 0)
		return ;

	if (check_map_position(data, dda_ray, pos) == 1)
			return ;
	while (1)
	{
		dda_ray->y += dda_ray->variable_side;
		dda_ray->x += dda_ray->fixed_side;
		dda_ray->length += dda_ray->hl;
		if (check_map_position(data, dda_ray, pos) == 1)
			return ;
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
		offset = (double)UNIT - pos_offset;
	dda_ray->y += offset * dda_ray->variable_side;
	dda_ray->x += offset * dda_ray->fixed_side;
	dda_ray->length += offset * dda_ray->hl;

	dda_ray->variable_side *= (double)UNIT;
	dda_ray->fixed_side *= (double)UNIT;
	dda_ray->hl *= (double)UNIT;
}

void	get_y_initial_length(t_dda_ray *dda_ray, double pos_offset)
{
	double	offset;

	if (dda_ray->hl == 0)
		return ;
	if (dda_ray->fixed_side < 0)
		offset = pos_offset;
	else
		offset = (double)UNIT - pos_offset;
	dda_ray->x += offset * dda_ray->variable_side;
	dda_ray->y += offset * dda_ray->fixed_side;
	dda_ray->length += offset * dda_ray->hl;

	dda_ray->variable_side *= (double)UNIT;
	dda_ray->fixed_side *= (double)UNIT;
	dda_ray->hl *= (double)UNIT;
}

//hl = hypotenuse_length
void	dda_algorithm(const t_data *data, t_ray *ray, t_vector *player_pos_offset)
{
	t_dda_ray	x_dda_ray;
	t_dda_ray	y_dda_ray;
	
	if (!data->map)
		return ;
	init_dda_ray(&x_dda_ray, ray->vector.y, ray->vector.x);
	init_dda_ray(&y_dda_ray, ray->vector.x, ray->vector.y);

	get_x_initial_length(&x_dda_ray, player_pos_offset->x);
	get_y_initial_length(&y_dda_ray, player_pos_offset->y);
	get_x_dda_ray_length(data, &x_dda_ray, &data->player->pos);
	get_y_dda_ray_length(data, &y_dda_ray, &data->player->pos);

	if (x_dda_ray.length < y_dda_ray.length)
	{
		ray->vector.x = x_dda_ray.x + data->player->pos.x;
		ray->vector.y = x_dda_ray.y + data->player->pos.y;
		ray->length = x_dda_ray.length;
	}
	else
	{
		ray->vector.x = y_dda_ray.x + data->player->pos.x;
		ray->vector.y = y_dda_ray.y + data->player->pos.y;
		ray->length = y_dda_ray.length;
	}
	(void)player_pos_offset;
}









/* int	main()
{
	int l;
	double a;

	l = get_segment_length(-200, 40);
	a = l;
	a = a;
	printf("m: %f\n", a);
	return (0);
} */

/* 
int	main()
{
	t_player	*p;


	p = init_player()
	return (0);
} */