
#include "cubed.h"

int	get_fp_segment_length(int a, int b)
{
	double		fp_length;
	long int	m;

	m = (a * POINT_SHIFTER) / b;
	m = (m * m) / POINT_SHIFTER;

	fp_length = m;
	fp_length = 1 + (fp_length / POINT_SHIFTER);
	fp_length = sqrt(fp_length);
	fp_length *= POINT_SHIFTER;
	return ((int)fp_length);
}

int	get_multiplicator(int pos)
{
	while (pos > UNIT)
		pos -= UNIT;
	return (pos);
}

void	get_y_ray_length(t_fp_ray *fp_ray, t_vector *pos, const char **map)
{
	if (fp_ray->hl == 0)
		return ;
	fp_ray->x += (UNIT - get_multiplicator(pos->y)) * fp_ray->variable_side;
	fp_ray->y += (UNIT - get_multiplicator(pos->y)) * fp_ray->fixed_side;
	fp_ray->length += (UNIT - get_multiplicator(pos->y)) * fp_ray->hl;
	if ((fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT < 0 || \
		(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT > 15 || \
		(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT < 0 || \
		(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT > 25) //the fixed values need to be replaced
		return ;
	if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')
		return ;
	fp_ray->variable_side *= UNIT;
	fp_ray->fixed_side *= UNIT;
	fp_ray->hl *= UNIT;
	while (1/* fp_ray->length / POINT_SHIFTER <= MAX_RAY_LENGTH */)
	{
		fp_ray->x += fp_ray->variable_side;
		fp_ray->y += fp_ray->fixed_side;
		fp_ray->length += fp_ray->hl;
		if ((fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT < 0 || \
			(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT > 15 || \
			(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT < 0 || \
			(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT > 25) //the fixed values need to be replaced
			return ;
		if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')
		{
			return ;
		}
	}
}

void	get_x_ray_length(t_fp_ray *fp_ray, t_vector *pos, const char **map)
{
	if (fp_ray->hl == 0)
		return ;
	fp_ray->y += (UNIT - get_multiplicator(pos->x)) * fp_ray->variable_side;
	fp_ray->x += (UNIT - get_multiplicator(pos->x)) * fp_ray->fixed_side;
	fp_ray->length += (UNIT - get_multiplicator(pos->x)) * fp_ray->hl;

	if ((fp_ray->y / POINT_SHIFTER / UNIT) + (pos->y / UNIT) < 0 || \
		(fp_ray->y / POINT_SHIFTER / UNIT) + (pos->y / UNIT) > 15 || \
		(fp_ray->x / POINT_SHIFTER / UNIT) + (pos->x / UNIT) < 0 || \
		(fp_ray->x / POINT_SHIFTER / UNIT) + (pos->x / UNIT) > 25) //the fixed values need to be replaced
		return ;
	if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')		
		return ;
	fp_ray->variable_side *= UNIT;
	fp_ray->fixed_side *= UNIT;
	fp_ray->hl *= UNIT;
	while (1/* fp_ray->length / POINT_SHIFTER <= MAX_RAY_LENGTH */)
	{
		fp_ray->y += fp_ray->variable_side;
		fp_ray->x += fp_ray->fixed_side;
		fp_ray->length += fp_ray->hl;
		if ((fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT < 0 || \
				(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT > 15 || \
				(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT < 0 || \
				(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT > 25) //the fixed values need to be replaced
		{
			return ;
		}
		if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x/ UNIT] == '1')
		{
			return ;
		}
	}
}

void	init_fp_ray(t_fp_ray *fp_ray, long int a, long int b)
{
	fp_ray->fixed_side = POINT_SHIFTER;
	fp_ray->length = 0;
	fp_ray->x = 0;
	fp_ray->y = 0;
	if (a == 0)
	{
		fp_ray->variable_side = 0;
		fp_ray->hl = POINT_SHIFTER;
	}
	else if (b == 0)
	{
		fp_ray->variable_side = POINT_SHIFTER;
		fp_ray->hl = POINT_SHIFTER;
		fp_ray->fixed_side = 0;
		if (a < 0 && b == 0)
			fp_ray->variable_side *= -1;
	}
	else
	{
		fp_ray->variable_side = (a * POINT_SHIFTER) / b;
		fp_ray->hl = get_fp_segment_length(a, b);
	}
	if (b < 0)
	{
		fp_ray->variable_side *= -1;
		fp_ray->fixed_side *= -1;
	}
}

//hl = hypotenuse_length
void	dda_algorithm(t_player *player, t_vector *max_ray, const char **map, long int *fp_length)
{
	t_fp_ray	fp_x_ray;
	t_fp_ray	fp_y_ray;
	
	if (!map)
		return ;
	init_fp_ray(&fp_x_ray, max_ray->y, max_ray->x);
	init_fp_ray(&fp_y_ray, max_ray->x, max_ray->y);
	get_x_ray_length(&fp_x_ray, &player->pos, map);
	get_y_ray_length(&fp_y_ray, &player->pos, map);
	if (fp_x_ray.length < fp_y_ray.length)
	{
		max_ray->x = (fp_x_ray.x) / POINT_SHIFTER;
		max_ray->y = (fp_x_ray.y) / POINT_SHIFTER;
		*fp_length = fp_x_ray.length;
	}
	else
	{
		max_ray->x = fp_y_ray.x / POINT_SHIFTER;
		max_ray->y = fp_y_ray.y / POINT_SHIFTER;
		*fp_length = fp_y_ray.length;
	}
}









/* int	main()
{
	int l;
	double a;

	l = get_fp_segment_length(-200, 40);
	a = l;
	a = a / POINT_SHIFTER;
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