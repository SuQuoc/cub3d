
#include "cubed.h"

void	init_vector(t_vector *vector, int x_position, int y_position)
{
	vector->x = x_position;
	vector->y = y_position;
}

static t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	init_vector(&player->pos, WINDOW_W / 2, WINDOW_H / 2);
	init_vector(&player->fp_direction, \
					0 * POINT_SHIFTER, -100 * POINT_SHIFTER);
	init_vector(&player->fp_camera_right, \
					60 * POINT_SHIFTER, 0 * POINT_SHIFTER);				
	init_vector(&player->fp_camera_left, \
					-60 * POINT_SHIFTER, 0 * POINT_SHIFTER);
	init_vector(&player->direction, player->pos.x + 0, player->pos.y - 100);
	init_vector(&player->camera_right, 60, 0);
	init_vector(&player->camera_left, -60, 0);
	player->fast_axis = 'y';
	player->fast_diff = 100;
	player->slow_diff = 0;
	player->fault = 50;
	return (player);
}

t_data *init_data(void)
{
	t_data *data;
	
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		perror(NULL);
		exit(1);
	}
	data->player = init_player();
	if (!data->player)
	{
		perror(NULL);
		free(data);
		exit(1);
	}
	calculate_rays(data->player);
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

void	init_line(t_line *line, const t_vector *start, const t_vector *end)
{
	line->start_x = start->x;
	line->start_y = start->y;
	line->end_x = end->x;
	line->end_y = end->y;
	line->x_diff = (line->end_x - line->start_x);
	line->y_diff = (line->end_y - line->start_y);
	line_calculate_values(line);
}
