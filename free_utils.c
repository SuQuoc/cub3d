
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
	//overly protection? bad? unneccessary!
	if (!data || !data->mlx_ptr)
		return ;
	if (data->N_texture)
		mlx_destroy_image(data->mlx_ptr, data->N_texture);
	if (data->E_texture)
		mlx_destroy_image(data->mlx_ptr, data->E_texture);
	if (data->S_texture)
		mlx_destroy_image(data->mlx_ptr, data->S_texture);
	if (data->W_texture)
		mlx_destroy_image(data->mlx_ptr, data->W_texture);
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
void free_data_code(t_data *data, int err_code)
{
	if (err_code != 0)
	{
		err_code = 1;
		file_error(err_code);
	}
	if (data->mlx_ptr)
	{
		destroy_textures(data);
		mlx_destroy_display(data->mlx_ptr);
	}
	free(data->player);
	free(data->mlx_ptr);
	free_2d_array(data->map);
	if (data->map_copy)
		free_2d_array(data->map_copy);
	free(data);
	data = NULL;
	exit(err_code);
}