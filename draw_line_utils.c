
#include "cubed.h"

void	fast_y_xneg_yneg(t_data *data, t_point *point)//3
{
	while (point->start_y >= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x--;
		}
		point->start_y--;
	}
}

void	fast_x_xneg_yneg(t_data *data, t_point *point)//4
{
	while (point->start_x >= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->y_diff;
		if (point->fault <= 0)
		{
			point->fault += point->x_diff;
			point->start_y--;
		}
		point->start_x--;
	}
}

void	fast_x_xneg_ypos(t_data *data, t_point *point)//5
{
	while (point->start_x >= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->y_diff;
		if (point->fault <= 0)
		{
			point->fault += point->x_diff;
			point->start_y++;
		}
		point->start_x--;
	}
}

void	fast_y_xneg_ypos(t_data *data, t_point *point)//6
{
	while (point->start_y <= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x--;
		}
		point->start_y++;
	}
}
