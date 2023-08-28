
#include "cubed.h"

void	get_y_ray_length(const t_data *data, t_ray *ray, t_vector *pos, int ps)
{
	if (ray->hl == 0)
		return ;

	if ((ray->y + pos->y) / UNIT < 0 || (ray->y + pos->y) / UNIT > data->map_height -1|| \
			(ray->x + pos->x) / UNIT < 0 || (ray->x + pos->x) / UNIT > data->map_width -1|| \
			(ray->y + pos->y + ps) / UNIT < 0 || (ray->y + pos->y + ps) / UNIT > data->map_height -1|| \
			(ray->x + pos->x + ps) / UNIT < 0 || (ray->x + pos->x + ps) / UNIT > data->map_width-1)
		return ;
	if (data->map[(int)((ray->y + pos->y + ps) / UNIT)][(int)((ray->x + pos->x + ps) / UNIT)] == '1')	
		return ;
	while (1)
	{
		ray->x += ray->variable_side;
		ray->y += ray->fixed_side;
		ray->length += ray->hl;
		if ((ray->y + pos->y) / UNIT < 0 || (ray->y + pos->y) / UNIT > data->map_height-1 || \
			(ray->x + pos->x) / UNIT < 0 || (ray->x + pos->x) / UNIT > data->map_width -1|| \
			(ray->y + pos->y + ps) / UNIT < 0 || (ray->y + pos->y + ps) / UNIT > data->map_height -1|| \
			(ray->x + pos->x + ps) / UNIT < 0 || (ray->x + pos->x + ps) / UNIT > data->map_width-1)
			return ;
		if (data->map[(int)((ray->y + pos->y + ps) / UNIT)][(int)((ray->x + pos->x + ps) / UNIT)] == '1')	
			return ;
	}
}

void	get_x_ray_length(const t_data *data, t_ray *ray, t_vector *pos, int ps)
{
	if (ray->hl == 0)
		return ;

	if ((ray->y + pos->y) / UNIT < 0 || (ray->y + pos->y) / UNIT > data->map_height -1|| \
			(ray->x + pos->x) / UNIT < 0 || (ray->x + pos->x) / UNIT > data->map_width -1|| \
			(ray->y + pos->y + ps) / UNIT < 0 || (ray->y + pos->y + ps) / UNIT > data->map_height -1|| \
			(ray->x + pos->x + ps) / UNIT < 0 || (ray->x + pos->x + ps) / UNIT > data->map_width-1)
		return ;
	if (data->map[(int)((ray->y + pos->y + ps) / UNIT)][(int)((ray->x + pos->x + ps) / UNIT)] == '1')
		return ;
	while (1)
	{
		ray->y += ray->variable_side;
		ray->x += ray->fixed_side;
		ray->length += ray->hl;
		if ((ray->y + pos->y) / UNIT < 0 || (ray->y + pos->y) / UNIT > data->map_height -1|| \
			(ray->x + pos->x) / UNIT < 0 || (ray->x + pos->x) / UNIT > data->map_width -1|| \
			(ray->y + pos->y + ps) / UNIT < 0 || (ray->y + pos->y + ps) / UNIT > data->map_height-1 || \
			(ray->x + pos->x + ps) / UNIT < 0 || (ray->x + pos->x + ps) / UNIT > data->map_width-1)
			return ;
		if (data->map[(int)((ray->y + pos->y + ps) / UNIT)][(int)((ray->x + pos->x + ps) / UNIT)] == '1')
			return ;
	}
}


void	get_x_pos_initial_length(t_ray *ray, t_vector *pos, int *ps)
{
	if (ray->hl == 0)
		return ;
	ray->y += (UNIT - get_multiplicator(pos->x)) * ray->variable_side;
	ray->x += (UNIT - get_multiplicator(pos->x)) * ray->fixed_side;
	ray->length += (UNIT - get_multiplicator(pos->x)) * ray->hl;

	ray->variable_side *= UNIT;
	ray->fixed_side *= UNIT;
	ray->hl *= UNIT;
	*ps = 0;
}
void	get_y_pos_initial_length(t_ray *ray, t_vector *pos, int *ps)
{
	if (ray->hl == 0)
		return ;
	ray->x += (UNIT - get_multiplicator(pos->y)) * ray->variable_side;
	ray->y += (UNIT - get_multiplicator(pos->y)) * ray->fixed_side;
	ray->length += (UNIT - get_multiplicator(pos->y)) * ray->hl;

	ray->variable_side *= UNIT;
	ray->fixed_side *= UNIT;
	ray->hl *= UNIT;
	*ps = 0;
}
void	get_x_neg_initial_length(t_ray *ray, t_vector *pos, int *ps)
{
	if (ray->hl == 0)
		return ;
	ray->y += (get_multiplicator(pos->x)) * ray->variable_side;
	ray->x += (get_multiplicator(pos->x)) * ray->fixed_side;
	ray->length += (get_multiplicator(pos->x)) * ray->hl;

	ray->variable_side *= UNIT;
	ray->fixed_side *= UNIT;
	ray->hl *= UNIT;
	*ps = -1;
}
void	get_y_neg_initial_length(t_ray *ray, t_vector *pos, int *ps)
{
	if (ray->hl == 0)
		return ;
	ray->x += (get_multiplicator(pos->y)) * ray->variable_side;
	ray->y += (get_multiplicator(pos->y)) * ray->fixed_side;
	ray->length += (get_multiplicator(pos->y)) * ray->hl;

	ray->variable_side *= UNIT;
	ray->fixed_side *= UNIT;
	ray->hl *= UNIT;
	*ps = -1;
}

//hl = hypotenuse_length
//ps = position-shifter, its for "shifting"(+1) the position on the map, when ray->fixed_side is negative
void	dda_algorithm(const t_data *data, t_vector *max_ray, double *length)
{
	t_ray	x_ray;
	t_ray	y_ray;
	int		ps;
	
	if (!data->map)
		return ;
	init_ray(&x_ray, max_ray->y, max_ray->x);
	init_ray(&y_ray, max_ray->x, max_ray->y);

	if (x_ray.fixed_side > 0)
		get_x_pos_initial_length(&x_ray, &data->player->pos, &ps);
	else
		get_x_neg_initial_length(&x_ray, &data->player->pos, &ps);
	get_x_ray_length(data, &x_ray, &data->player->pos, ps);
	if (y_ray.fixed_side > 0)
		get_y_pos_initial_length(&y_ray, &data->player->pos, &ps);
	else
		get_y_neg_initial_length(&y_ray, &data->player->pos, &ps);

	get_y_ray_length(data, &y_ray, &data->player->pos, ps);
	if (x_ray.length < y_ray.length)
	{
		max_ray->x = (x_ray.x);
		max_ray->y = (x_ray.y);
		*length = x_ray.length;
	}
	else
	{
		max_ray->x = y_ray.x;
		max_ray->y = y_ray.y;
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