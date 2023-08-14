


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