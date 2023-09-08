
#include "cubed.h"

static void	line_calculate_values(t_line *line)
{
	if (line->x_diff < 0)
	{
		line->x_diff *= -1;
		line->x_pos_or_neg = 'n';
	}
	else
		line->x_pos_or_neg = 'p';
	if (line->y_diff < 0)
	{
		line->y_diff *= -1;
		line->y_pos_or_neg = 'n';
	}
	else
		line->y_pos_or_neg = 'p';
	if (line->x_diff > line->y_diff)
	{
		line->fault = line->x_diff / 2;
		line->fast_axis = 'x';
	}
	else
	{
		line->fault = line->y_diff / 2;
		line->fast_axis = 'y';
	}
}

void	init_line(t_line *line, const t_vector start, const t_vector end)
{
	line->start_x = start.x;
	line->start_y = start.y;
	line->end_x = end.x;
	line->end_y = end.y;
	line->x_diff = (line->end_x - line->start_x);
	line->y_diff = (line->end_y - line->start_y);
	line_calculate_values(line);
}

void	declare_base_values(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->map_copy = NULL;
	data->err = 0;
	data->cos = cos(PI / 180 * ROTATITON_SPEED);
	data->sin = sin(PI / 180 * ROTATITON_SPEED);
}
