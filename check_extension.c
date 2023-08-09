
#include "cubed.h"

//GNL has always a newline also at the endline which in a file has no nl technically

int check_extension(char *str)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(str);
	ext_len = ft_strlen(EXTENSION);

	if (ft_strncmp(&str[len - ext_len], EXTENSION, ext_len + 1) == 0 && str[0] != '.')
		return (1);
	error_msg();
	ft_putstr_fd("Wrong file type (extension)!\n", 2);
	return (0);
}

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
		if (!gnl)
			break;  
		loop_idf_line(gnl);
	}
	free(gnl);
}

void loop_idf_line(char *str)
{
	int i;
	int err;
	i = 0;

	if (str && str[0] == '\n')
		return ;

	while (str[i] && (is_blank(str[i]) || str[i] == '\n'))
		i++;
	if (str[i])
	{
		err = search_idf(&str[i]);
		free(str); //here or 1 scope out
		if (err)
			return (free_data());
		
	}
}


void loop_map(int fd)
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

void loop_map_line()
{

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