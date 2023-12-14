
#include "cubed.h"

static void	init_dda_ray_edgecase(t_dda_ray *dda_ray, double a, double b)
{
	if (a == 0)
	{
		dda_ray->variable_side = 0;
		dda_ray->hl = 1;
	}
	if (b == 0)
	{
		dda_ray->variable_side = 1;
		dda_ray->hl = 0;
		dda_ray->fixed_side = 0;
		if (a < 0 && b == 0)
			dda_ray->variable_side *= -1;
	}
}

static void	init_dda_ray(t_dda_ray *dda_ray, double a, double b)
{
	dda_ray->fixed_side = 1;
	dda_ray->length = 0;
	dda_ray->x = 0;
	dda_ray->y = 0;
	if (a == 0 || b == 0)
		init_dda_ray_edgecase(dda_ray, a, b);
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

static void	get_shorter_ray(const t_data *data, t_ray *ray, \
								t_dda_ray *x_dda_ray, t_dda_ray *y_dda_ray)
{
	if ((x_dda_ray->length < y_dda_ray->length && x_dda_ray->length > 0.5) || \
													y_dda_ray->length < 0.5)
	{
		ray->vector.x = x_dda_ray->x + data->player->pos.x;
		ray->vector.y = x_dda_ray->y + data->player->pos.y;
		ray->length = x_dda_ray->length * ray->angle;
		ray->shorter_ray = 'x';
	}
	else
	{
		ray->vector.x = y_dda_ray->x + data->player->pos.x;
		ray->vector.y = y_dda_ray->y + data->player->pos.y;
		ray->length = y_dda_ray->length * ray->angle;
		ray->shorter_ray = 'y';
	}
}

//hl = hypotenuse_length
void	dda_algorithm(const t_data *data, t_ray *ray, \
									t_vector *player_pos_offset)
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
	get_shorter_ray(data, ray, &x_dda_ray, &y_dda_ray);
}
