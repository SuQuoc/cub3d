
#include "cubed.h"

t_data *init_data(void)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if (!data)
	{
		error_msg();
		exit(1);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->N_texture = NULL;
	data->E_texture = NULL;
	data->S_texture = NULL;
	data->W_texture = NULL;
	return (data);
}

static void	point_calculate_values(t_point *point)
{
	point->x_diff = (point->end_x - point->start_x);
	point->y_diff = (point->end_y - point->start_y);
	if (point->y_diff < 0)
	{
		point->y_diff *= -1;
		point->pos_or_neg = 'n';
	}
	else
		point->pos_or_neg = 'p';
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

t_point	*init_point(int point_one_x, int point_one_y, \
						int point_two_x, int point_two_y)
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
	point_calculate_values(point);
	return (point);
}
