

void loop_idf(t_data *data)
{
	int i;

	i = 0;
	if (data->map)
		return ;
	while (data->map[i])
	{
		if (loop_idf_line(data->map[i], data) == 1)
            break ;
		i++;
	}
}

void loop_idf_line(char *str, t_data *data)
{
	int err;

	if (!str)
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