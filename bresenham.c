
#include "cubed.h"

void	calculate_other_values(t_point *point)
{
	point->x_diff = (point->end_x - point->start_x);
	point->y_diff = (point->end_y - point->start_y);
	if (point->y_diff < 0)
		point->y_diff *= -1;
	if (point->x_diff > point->y_diff)
	{
		point->fault = point->x_diff / 2;
		point->fast_axis = 'x';
	}
	else
	{
		point->fault = point->y_diff / 2;
		point->fast_axis = 'y';
	}
}

t_point	*init_point(int point_one_x, int point_one_y, int point_two_x, int point_two_y)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	if (!point)
	{
		ft_putstr_fd((char*)"Error: malloc failed in function 'init_point'\n", 2);
		return (NULL);
	}
		
	if (point_one_x < point_two_x)
	{
		point->start_x = point_one_x;
		point->start_y = point_one_y;
		point->end_x = point_two_x;
		point->end_y = point_two_y;
	}
	else
	{
		point->start_x = point_two_x;
		point->start_y = point_two_y;
		point->end_x = point_one_x;
		point->end_y = point_one_y;
	}
	calculate_other_values(point);
	return (point);
}

int	draw_line(int point_one_x, int point_one_y, int point_two_x, int point_two_y)
{
	t_point *point;

	point = init_point(point_one_x, point_one_y, point_two_x, point_two_y);
	if (!point)
		return (1);


	free(point);
	return (0);
}