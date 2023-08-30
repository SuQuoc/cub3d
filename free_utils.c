
#include "cubed.h"

void	free_2d_array(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

//mlx_destroy_image(mlx, NULL)
//mlx_destroy_image(NULL, texture)
//both lead to errors so we have to check before if they are not null
void destroy_textures(t_data *data)
{
	free_image(data->N_texture, data->mlx_ptr);
	free_image(data->E_texture, data->mlx_ptr);
	free_image(data->S_texture, data->mlx_ptr);
	free_image(data->W_texture, data->mlx_ptr);
}

void free_image(t_image *img, void *mlx_ptr)
{
	if (img)
	{
		if (img->img_ptr)
			mlx_destroy_image(mlx_ptr, img->img_ptr);
		free(img);
	}
}

void free_data(t_data *data)
{
	int exit_code;

	exit_code = 0;
	if (data->err != 0)
	{
		exit_code = 1;
		file_error(data->err);
	}
	free_image(data->img, data->mlx_ptr);
	if (data->mlx_ptr)
	{
		destroy_textures(data);
		mlx_destroy_display(data->mlx_ptr);
	}
	free(data->player);
	free(data->mlx_ptr);
	free_2d_array(data->map);
	free(data);
	data = NULL;
	exit(exit_code);
}

//if error_message is NULL it exits with 0, else with 1
void free_data_err(t_data *data, char *error_message)
{	
	free_image(data->img, data->mlx_ptr);
	if (data->mlx_ptr)
	{
		destroy_textures(data);
		mlx_destroy_display(data->mlx_ptr);
	}
	free(data->player);
	free(data->mlx_ptr);
	free_2d_array(data->map);
	free_2d_array(data->map_copy);
	free(data);
	data = NULL;
	if (error_message)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(error_message, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	exit(0);
}
