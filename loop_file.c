
#include "cubed.h"

void avoid_gnl_leaks(int fd)
{
	char *gnl;

	gnl = get_next_line(fd);

	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
}

void loop_file(int fd, t_data *data)
{
	int error;
	char *gnl;

	error = FALSE;
	gnl = ft_strdup("");
	
	loop_idf();
	if (data->err != 0)
		return (avoid_gnl_leaks(fd), close(fd), free_data(data, 1));
	loop_map();
	if (data->err != 0)
		return (avoid_gnl_leaks(fd), close(fd), free_data(data, 1));
	close(fd);
}

void loop_idf(int fd, t_data *data)
{
	int error;
	char *gnl;

	error = FALSE;
	gnl = ft_strdup("");	
	if (!gnl)
		malloc_error();
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		if (loop_idf_line(gnl) == 1)
	}
	free(gnl);
}

void loop_idf_line(char *str, t_data *data)
{
	int err;

	if (!str)
		return ;
	if (str[0] == '\n')
		return ;
	err = search_idf(str, data);
	free(str); //here or 1 scope out
	if (err)
		return (free_data());		
}


void loop_map(int fd, t_data *data)
{
	int error;
	char *gnl;
	
	error = FALSE;
	gnl = ft_strdup("");	
	if (!gnl)
		malloc_error();
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		if (!gnl)
			break;  
		error = loop_map_line(gnl);
		if (error)
			file_error(error);
	}

}

void loop_map_line(char *str, t_data *data)
{
	if (!str)
		return ;
	if (str[0] == '\n')
		return ;
	
}


void get_array_sizes(int *y, int *x)
{
	//good to make array const len? --> filling shorter len with space
	//probably
}

//int  check_texture_path(char *path)
//{
//	int fd;
//
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//	mlx_xpm_file_to_image()
//
//}