
#include "cubed.h"

static void	fast_x_positive_y(t_data *data, t_point *point)
{
	while (point->start_x <= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, 0xFF0000);
		point->fault -= point->y_diff;
		if (point->fault <= 0)
		{
			point->fault += point->x_diff;
			point->start_y++;
		}
		point->start_x++;
	}
}

static void	fast_x_negative_y(t_data *data, t_point *point)
{
	while (point->start_x <= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, 0xFF0000);
		point->fault -= point->y_diff;
		if (point->fault < 0)
		{
			point->fault += point->x_diff;
			point->start_y--;
		}
		point->start_x++;
	}
}

static void	fast_y_positive_y(t_data *data, t_point *point)
{
	while (point->start_y <= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, 0xFF0000);
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x++;
		}
		point->start_y++;
	}
}

static void	fast_y_negative_y(t_data *data, t_point *point)
{
	while (point->start_y >= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, 0xFF0000);
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x++;
		}
		point->start_y--;
	}
}

int	draw_line(t_data *data, t_point *point)
{
	if (point->fast_axis == 'x' && point->pos_or_neg == 'p')
		fast_x_positive_y(data, point);
	else if (point->fast_axis == 'x' && point->pos_or_neg == 'n')
		fast_x_negative_y(data, point);
	else if (point->fast_axis == 'y' && point->pos_or_neg == 'p')
		fast_y_positive_y(data, point);
	else if (point->fast_axis == 'y' && point->pos_or_neg == 'n')
		fast_y_negative_y(data, point);
	return (0);
}