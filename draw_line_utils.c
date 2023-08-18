
#include "cubed.h"

void	fast_y_xneg_yneg(const t_data *data, t_line *line, const int color)//3
{
	while (line->start_y >= line->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->x_diff;
		if (line->fault < 0)
		{
			line->fault += line->y_diff;
			line->start_x--;
		}
		line->start_y--;
	}
}

void	fast_x_xneg_yneg(const t_data *data, t_line *line, const int color)//4
{
	while (line->start_x >= line->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->y_diff;
		if (line->fault <= 0)
		{
			line->fault += line->x_diff;
			line->start_y--;
		}
		line->start_x--;
	}
}

void	fast_x_xneg_ypos(const t_data *data, t_line *line, const int color)//5
{
	while (line->start_x >= line->end_x)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->y_diff;
		if (line->fault <= 0)
		{
			line->fault += line->x_diff;
			line->start_y++;
		}
		line->start_x--;
	}
}

void	fast_y_xneg_ypos(const t_data *data, t_line *line, const int color)//6
{
	while (line->start_y <= line->end_y)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line->start_x, \
						line->start_y, color);
		line->fault -= line->x_diff;
		if (line->fault < 0)
		{
			line->fault += line->y_diff;
			line->start_x--;
		}
		line->start_y++;
	}
}
