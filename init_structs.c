
#include "cubed.h"

t_data *init_data(void)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror(NULL);
		exit(1);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->N_texture = NULL;
	data->E_texture = NULL;
	data->S_texture = NULL;
	data->W_texture = NULL;
	data->err = 0;
	data->txt_h = 50;
	data->txt_w = 50;
	return (data);
}

static void	point_calculate_values(t_point *point)
{
	if (point->x_diff < 0)
	{
		point->x_diff *= -1;
		point->x_pos_or_neg = 'n';
	}
	else
		point->x_pos_or_neg = 'p';
	if (point->y_diff < 0)
	{
		point->y_diff *= -1;
		point->y_pos_or_neg = 'n';
	}
	else
		point->y_pos_or_neg = 'p';
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

t_point	*init_point(int start_x, int start_y, int end_x, int end_y)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	if (!point)
	{
		ft_putstr_fd((char*)"Error: malloc failed in function 'init_point'\n", 2);
		return (NULL);
	}
	point->start_x = start_x;
	point->start_y = start_y;
	point->end_x = end_x;
	point->end_y = end_y;
	point->x_diff = (point->end_x - point->start_x);
	point->y_diff = (point->end_y - point->start_y);
	point_calculate_values(point);
	return (point);
}
