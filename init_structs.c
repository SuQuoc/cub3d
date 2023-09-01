
#include "cubed.h"

void	init_vector(t_vector *vector, double x_position, double y_position)
{
	vector->x = x_position;
	vector->y = y_position;
}

static t_player	*init_player(void)
{
	t_player	*player;
	int			x;

	x = 0;
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->ray = malloc(sizeof(t_ray) * RAY_NB);
	if (!player->ray)
	{
		free(player);
		return (NULL);
	}
	while (x < RAY_NB)
		player->ray[x++].angle = 1;
	player->fast_axis = 'x';
	player->fast_diff = 100;
	player->slow_diff = 0;
	player->fault = 50;
	return (player);
}

static t_image	*init_image(void)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img_ptr = NULL;
	image->addr = NULL;
	//image->bpp = 0;
	//image->line_len = 0;
	//image->endian = 0;
	return (image);
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
	data->img = init_image();
	if (!data->img)
	{
		perror(NULL);
		free(data->player->ray);
		free(data->player);
		free(data);
		exit(1);
	}
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->map_copy = NULL;
	data->N_texture = init_image();
	data->E_texture = init_image();
	data->S_texture = init_image();
	data->W_texture = init_image();
	data->err = 0;
	data->txt_h = 50;
	data->txt_w = 50;
	data->cos = cos(PI / 180 * ROTATITON_SPEED); //protection?
	data->sin = sin(PI / 180 * ROTATITON_SPEED); //protection?
	calculate_rays(data, data->player);
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
