
#include "cubed.h"

//fast_x means that x is the fast direction, xpos that x_diff is positive and xneg that x_diff is negative.
//the same goes for fast_y, ypos and yneg, just with y.
static void	fast_x_xpos_ypos(const t_data *data, t_line *line, const int color)//8
{
	while (line->start_x <= line->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->y_diff;
		if (line->fault <= 0)
		{
			line->fault += line->x_diff;
			line->start_y++;
		}
		line->start_x++;
	}
}

static void	fast_x_xpos_yneg(const t_data *data, t_line *line, const int color)//1
{
	while (line->start_x <= line->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->y_diff;
		if (line->fault < 0)
		{
			line->fault += line->x_diff;
			line->start_y--;
		}
		line->start_x++;
	}
}

static void	fast_y_xpos_ypos(const t_data *data, t_line *line, const int color)//7
{
	while (line->start_y <= line->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->x_diff;
		if (line->fault < 0)
		{
			line->fault += line->y_diff;
			line->start_x++;
		}
		line->start_y++;
	}
}

static void	fast_y_xpos_yneg(const t_data *data, t_line *line, const int color)//2
{
	while (line->start_y >= line->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->x_diff;
		if (line->fault < 0)
		{
			line->fault += line->y_diff;
			line->start_x++;
		}
		line->start_y--;
	}
}

void	draw_line(const t_data *data, const t_vector start, \
					const t_vector end, const int color)
{
	t_line	line;

	init_line(&line, start, end);
	if (line.x_pos_or_neg == 'p')
	{
		if (line.fast_axis == 'x' && line.y_pos_or_neg == 'p')
			fast_x_xpos_ypos(data, &line, color);
		else if (line.fast_axis == 'x' && line.y_pos_or_neg == 'n')
			fast_x_xpos_yneg(data, &line, color);
		else if (line.fast_axis == 'y' && line.y_pos_or_neg == 'p')
			fast_y_xpos_ypos(data, &line, color);
		else if (line.fast_axis == 'y' && line.y_pos_or_neg == 'n')
			fast_y_xpos_yneg(data, &line, color);
	}
	else
	{
		if (line.fast_axis == 'y' && line.y_pos_or_neg == 'n')
			fast_y_xneg_yneg(data, &line, color);
		else if (line.fast_axis == 'x' && line.y_pos_or_neg == 'n')
			fast_x_xneg_yneg(data, &line, color);
		else if (line.fast_axis == 'x' && line.y_pos_or_neg == 'p')
			fast_x_xneg_ypos(data, &line, color);
		else if (line.fast_axis == 'y' && line.y_pos_or_neg == 'p')
			fast_y_xneg_ypos(data, &line, color);
	}
}