
#include "cubed.h"

//fast_x means that x is the fast direction, xpos that x_diff is positive and xneg that x_diff is negative.
//the same goes for fast_y, ypos and yneg, just with y.
static void	fast_x_xpos_ypos(t_data *data, t_point *point)//8
{
	while (point->start_x <= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->y_diff;
		if (point->fault <= 0)
		{
			point->fault += point->x_diff;
			point->start_y++;
		}
		point->start_x++;
	}
}

static void	fast_x_xpos_yneg(t_data *data, t_point *point)//1
{
	while (point->start_x <= point->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->y_diff;
		if (point->fault < 0)
		{
			point->fault += point->x_diff;
			point->start_y--;
		}
		point->start_x++;
	}
}

static void	fast_y_xpos_ypos(t_data *data, t_point *point)//7
{
	while (point->start_y <= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
		point->fault -= point->x_diff;
		if (point->fault < 0)
		{
			point->fault += point->y_diff;
			point->start_x++;
		}
		point->start_y++;
	}
}

static void	fast_y_xpos_yneg(t_data *data, t_point *point)//2
{
	while (point->start_y >= point->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point->start_x, \
						point->start_y, WHITE);
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
	if (point->x_pos_or_neg == 'p')
	{
		if (point->fast_axis == 'x' && point->y_pos_or_neg == 'p')
			fast_x_xpos_ypos(data, point);
		else if (point->fast_axis == 'x' && point->y_pos_or_neg == 'n')
			fast_x_xpos_yneg(data, point);
		else if (point->fast_axis == 'y' && point->y_pos_or_neg == 'p')
			fast_y_xpos_ypos(data, point);
		else if (point->fast_axis == 'y' && point->y_pos_or_neg == 'n')
			fast_y_xpos_yneg(data, point);
	}
	else
	{
		if (point->fast_axis == 'y' && point->y_pos_or_neg == 'n')
			fast_y_xneg_yneg(data, point);
		else if (point->fast_axis == 'x' && point->y_pos_or_neg == 'n')
			fast_x_xneg_yneg(data, point);
		else if (point->fast_axis == 'x' && point->y_pos_or_neg == 'p')
			fast_x_xneg_ypos(data, point);
		else if (point->fast_axis == 'y' && point->y_pos_or_neg == 'p')
			fast_y_xneg_ypos(data, point);
	}
	return (0);
}