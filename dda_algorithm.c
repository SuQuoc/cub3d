
#include "cubed.h"

void	get_y_ray_length(const t_data *data, t_ray *ray, t_vector *pos)
{
	if (ray->hl == 0)
		return ;

	if (check_map_position(data, ray, pos) == 1)
			return ;
	while (1)
	{
		ray->x += ray->variable_side;
		ray->y += ray->fixed_side;
		ray->length += ray->hl;
		if (check_map_position(data, ray, pos) == 1)
			return ;
	}
}

void	get_x_ray_length(const t_data *data, t_ray *ray, t_vector *pos)
{
	if (ray->hl == 0)
		return ;

	if (check_map_position(data, ray, pos) == 1)
			return ;
	while (1)
	{
		ray->y += ray->variable_side;
		ray->x += ray->fixed_side;
		ray->length += ray->hl;
		if (check_map_position(data, ray, pos) == 1)
			return ;
	}
}

void	get_x_initial_length(t_ray *ray, double pos)
{
	double	multiplicator;

	if (ray->hl == 0)
		return ;
	if (ray->fixed_side < 0)
		multiplicator = get_multiplicator(pos);
	else
		multiplicator = (double)UNIT - get_multiplicator(pos);
	ray->y += multiplicator * ray->variable_side;
	ray->x += multiplicator * ray->fixed_side;
	ray->length += multiplicator * ray->hl;

	ray->variable_side *= (double)UNIT;
	ray->fixed_side *= (double)UNIT;
	ray->hl *= (double)UNIT;
}

void	get_y_initial_length(t_ray *ray, double pos)
{
	double	multiplicator;

	if (ray->hl == 0)
		return ;
	if (ray->fixed_side < 0)
		multiplicator = get_multiplicator(pos);
	else
		multiplicator = (double)UNIT - get_multiplicator(pos);
	ray->x += multiplicator * ray->variable_side;
	ray->y += multiplicator * ray->fixed_side;
	ray->length += multiplicator * ray->hl;

	ray->variable_side *= (double)UNIT;
	ray->fixed_side *= (double)UNIT;
	ray->hl *= (double)UNIT;
}

//hl = hypotenuse_length
void	dda_algorithm(const t_data *data, t_vector *max_ray, double *length)
{
	t_ray	x_ray;
	t_ray	y_ray;
	
	if (!data->map)
		return ;
	init_ray(&x_ray, max_ray->y, max_ray->x);
	init_ray(&y_ray, max_ray->x, max_ray->y);

	get_x_initial_length(&x_ray, data->player->pos.x);
	get_y_initial_length(&y_ray, data->player->pos.y);
	get_x_ray_length(data, &x_ray, &data->player->pos);
	get_y_ray_length(data, &y_ray, &data->player->pos);

	if (x_ray.length < y_ray.length)
	{
		max_ray->x = x_ray.x + data->player->pos.x;
		max_ray->y = x_ray.y + data->player->pos.y;
		*length = x_ray.length;
	}
	else
	{
		max_ray->x = y_ray.x + data->player->pos.x;
		max_ray->y = y_ray.y + data->player->pos.y;
		*length = y_ray.length;
	}
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