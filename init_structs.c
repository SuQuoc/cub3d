
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
	player->ray = NULL;
	player->ray = malloc(sizeof(t_ray) * RAY_NB);
	if (!player->ray)
		return (NULL);
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

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img_ptr = NULL;
	image->addr = NULL;
	image->bpp = 0;
	image->line_len = 0;
	image->height = 0;
	image->endian = 0;
	return (image);
}

static void	init_txtr_images(t_data *data)
{
	data->n_texture = init_image();
	data->e_texture = init_image();
	data->s_texture = init_image();
	data->w_texture = init_image();
	if (!data->n_texture || !data->e_texture || !data->s_texture
		|| !data->w_texture)
	{
		perror(NULL);
		free_data(data);
	}
}

// init image for txtr not protected
t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		perror(NULL);
		exit(1);
	}
	declare_base_values(data);
	data->player = init_player();
	if (!data->player)
		free_data(data);
	data->img = init_image();
	if (!data->img)
		free_data_err(data, "Malloc failed!");
	init_txtr_images(data);
	return (data);
}
