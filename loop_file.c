
#include "cubed.h"

//in ft_strmerge gibts noch ne risk wenn s1 NULL ist wird gemalloced
char *read_map_into_str(int fd)
{
	char	*buf;
	char 	*file;
	char	*temp;
	int		check;

	file = NULL;
	buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (free(buf), free(file), NULL);
		if (check == 0)
			break ;
		buf[check] = '\0';
		temp = ft_strmerge(file, buf);
		if (!temp)
			return (free(buf), free(file), NULL);
		file = temp;
	}
	return (free(buf), file);
}


//void avoid_gnl_leaks(int fd)
//{
//	char *gnl;
//
//	gnl = get_next_line(fd);
//
//	while (gnl)
//	{
//		free(gnl);
//		gnl = get_next_line(fd);
//	}
//}

int loop_file(int fd, t_data *data)
{
	char *map_str;

	map_str = read_map_into_str(fd);
	close(fd);
	if (!map_str)
		return (1);
	data->map = ft_split(map_str, '\n');
	if (!data->map)
		return (1);
	printf("giga str:\n%s", map_str);
	free(map_str);
	print_str_arr(data->map);
	return (0);
	//loop_idf();
	//if (data->err != 0)
	//	return (free_data(data, 1));
	//loop_map();
	//if (data->err != 0)
	//	return (free_data(data, 1));
}


































































