
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

void	get_x_ray_length(t_fp_ray *fp_ray, t_vector *pos, const char **map)
{
	map++;
	map--;
	if (fp_ray->hl == 0)
		return ;
	fp_ray->x += get_multiplicator(fp_ray->x + pos->x);
	fp_ray->y += fp_ray->s * get_multiplicator(fp_ray->y + pos->y);
	fp_ray->length += fp_ray->hl;
	if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')
	
		return ;
/* 	printf("get_x_ray_length: map: y: %li	x: %li\n", \
				(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT, \
				(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT); */
	fp_ray->hl *= UNIT;
	fp_ray->s *= UNIT;
/* 	printf("get_x_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length / POINT_SHIFTER , fp_ray->hl / POINT_SHIFTER, \
				fp_ray->s / POINT_SHIFTER, fp_ray->x / POINT_SHIFTER, fp_ray->y / POINT_SHIFTER);
	printf("get_x_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length , fp_ray->hl, fp_ray->s , fp_ray->x , fp_ray->y ); */
	while (fp_ray->length / POINT_SHIFTER <= MAX_RAY_LENGTH)
	{
		fp_ray->x += UNIT * POINT_SHIFTER;
		fp_ray->y += fp_ray->s;
		fp_ray->length += fp_ray->hl;
		printf("1\n");
		if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x/ UNIT] == '1')
		{
			return ;
		}
/* 		printf("get_x_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length / POINT_SHIFTER , fp_ray->hl / POINT_SHIFTER, \
				fp_ray->s / POINT_SHIFTER, fp_ray->x / POINT_SHIFTER, fp_ray->y / POINT_SHIFTER);
		printf("get_x_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length , fp_ray->hl, fp_ray->s , fp_ray->x , fp_ray->y ); */
	}
}

void	get_y_ray_length(t_fp_ray *fp_ray, t_vector *pos, const char **map)
{
	map++;
	map--;
	if (fp_ray->hl == 0)
		return ;
	fp_ray->x += fp_ray->s * get_multiplicator(fp_ray->x + pos->x);
	fp_ray->y += get_multiplicator(fp_ray->y + pos->y);
	fp_ray->length += fp_ray->hl;
	if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')
		return ;
	fp_ray->hl *= UNIT;
	fp_ray->s *= UNIT;
/* 	printf("get_y_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
			fp_ray->length / POINT_SHIFTER , fp_ray->hl / POINT_SHIFTER, \
			fp_ray->s / POINT_SHIFTER, fp_ray->x / POINT_SHIFTER, fp_ray->y / POINT_SHIFTER);
	printf("get_y_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length , fp_ray->hl, fp_ray->s , fp_ray->x , fp_ray->y ); */
	while (fp_ray->length / POINT_SHIFTER <= MAX_RAY_LENGTH)
	{
		fp_ray->x += fp_ray->s;
		fp_ray->y += UNIT * POINT_SHIFTER;
		fp_ray->length += fp_ray->hl;
		if (map[(fp_ray->y / POINT_SHIFTER / UNIT) + pos->y / UNIT]\
				[(fp_ray->x / POINT_SHIFTER / UNIT) + pos->x / UNIT] == '1')
		{
			printf("1\n");
			return ;
		}
/* 		printf("get_y_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
			fp_ray->length / POINT_SHIFTER , fp_ray->hl / POINT_SHIFTER, \
			fp_ray->s / POINT_SHIFTER, fp_ray->x / POINT_SHIFTER, fp_ray->y / POINT_SHIFTER);
		printf("get_y_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
				fp_ray->length , fp_ray->hl, fp_ray->s , fp_ray->x , fp_ray->y ); */
	}
}

void	init_fp_ray(t_fp_ray *fp_ray, long int a, long int b)
{
	if (a == 0)
	{
		fp_ray->hl = 0;
		fp_ray->s = 0;
	}
	else if (b == 0)
	{
		fp_ray->hl = POINT_SHIFTER;
		fp_ray->s = POINT_SHIFTER;
	}
	else
	{
		fp_ray->hl = get_fp_segment_length(a, b);
		fp_ray->s = (a * POINT_SHIFTER) / b;
	}
	fp_ray->length = 0;
	fp_ray->x = 0;
	fp_ray->y = 0;
}

//hl = hypotenuse_length
void	dda_algorithm(t_player *player, t_vector *max_ray, const char **map, long int *fp_length)
{
	t_fp_ray	fp_x_ray;
//	t_fp_ray	fp_y_ray;
	
	if (!map)
		return ;
	
	printf("max_ray: x: %i	y: %i\n", max_ray->x, max_ray->y);
//	init_fp_ray(&fp_y_ray, max_ray->x, max_ray->y);
	init_fp_ray(&fp_x_ray, max_ray->y, max_ray->x);
	get_x_ray_length(&fp_x_ray, &player->pos, map);
//	get_y_ray_length(&fp_y_ray, &player->pos, map);
/* 	printf("get_y_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
			fp_y_ray.length / POINT_SHIFTER, fp_y_ray.hl / POINT_SHIFTER, \
			fp_y_ray.s / POINT_SHIFTER, fp_y_ray.x / POINT_SHIFTER, fp_y_ray.y / POINT_SHIFTER); */
	printf("get_x_ray_length: length: %li	hl: %li	s: %li	x: %li	y: %li\n", \
			fp_x_ray.length / POINT_SHIFTER , fp_x_ray.hl / POINT_SHIFTER, \
			fp_x_ray.s / POINT_SHIFTER, fp_x_ray.x / POINT_SHIFTER, fp_x_ray.y / POINT_SHIFTER);
	return ;
	if (fp_x_ray.length > MAX_RAY_LENGTH/*  && fp_y_ray.length > MAX_RAY_LENGTH */)
	{
		*fp_length = MAX_RAY_LENGTH;
		return ;
	}
/* 	if (fp_x_ray.length < fp_y_ray.length)
	{ */
		max_ray->x = fp_x_ray.x / POINT_SHIFTER;
		max_ray->y = fp_x_ray.y / POINT_SHIFTER;
		*fp_length = fp_x_ray.length;
/* 	}
	else
	{
		max_ray->x = fp_y_ray.x / POINT_SHIFTER;
		max_ray->y = fp_y_ray.y / POINT_SHIFTER;
		*fp_length = fp_y_ray.length;
	} */
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