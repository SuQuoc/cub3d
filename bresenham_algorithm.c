
#include "cubed.h"

void	fast_x_positive_y(t_point *point)
{
	while (point->start_x < point->end_x)
	{
		//mlx pixelput
		point->fault -= point->y_diff;
		if (point->fault < 0)
		{
			point->fault += point->x_diff;
			point->start_y++;
		}
		point->start_x++;
	}
}

void	fast_x_negative_y(t_point *point)
{
	while (point->start_x < point->end_x)
	{
		//mlx pixelput
		point->fault -= point->y_diff;
		if (point->fault < 0)
		{
			point->fault += point->x_diff;
			point->start_y--;
		}
		point->start_x++;
	}
}

void	fast_y_positive_y(t_point *point)
{
	while (point->start_y < point->end_y)
	{
		//mlx pixelput
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x++;
		}
		point->start_y++;
	}
}

void	fast_y_negative_y(t_point *point)
{
	while (point->start_y < point->end_y)
	{
		//mlx pixelput
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x--;
		}
		point->start_y++;
	}
}
