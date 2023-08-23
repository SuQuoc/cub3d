
#include "cubed.h"

int	get_segment_length(int a, int b)
{
	double		ps_length;
	long int	m;

	m = (a * POINT_SHIFTER) / b;
	m = (m * m) / POINT_SHIFTER;

	ps_length = m;
	ps_length = 1 + (ps_length / POINT_SHIFTER);
	ps_length = sqrt(ps_length);
	ps_length *= POINT_SHIFTER;
	return ((int)ps_length);
}

int	get_multiplicator(int pos)
{
	while (pos > UNIT)
		pos -= UNIT;
	return (pos);
}

int	dda_algorithm(t_player *player, t_vector *ray)
{
	int	length;
	int	s_x;
	int	s_y;
	int	x;

	x = 0;
	length = 0;
	s_y = ray->x / ray->y * UNIT;
	s_x = ray->y / ray->x * UNIT;
	while (length < RAY_LENGTH * POINT_SHIFTER)
	{


		x++;
	}
}

/* 
int	main()
{
	int l;
	double a;

	l = get_segment_length(3, 4);
	a = l;
	a = a / POINT_SHIFTER;
	printf("m: %f\n", a);
	return (0);
} */