
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


void loop_file(int fd, t_data *data)
{
	char *map_str;

	map_str = read_map_into_str(fd);
	close(fd);
	if (!map_str)
		return (free_data_err(data, "malloc fail in loop_file() map_str"));
	if (prelim_checks_passed(map_str, data) == FALSE)
		return (free(map_str), free_data(data));
	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (!data->map)
		return (free_data_err(data, "malloc fail in loop_file() data->map"));
	loop_idf(data);
	if (data->err != 0)
		return (free_data(data));
	cut_idfs_from_map(data);
	data->map_copy = copy_2d_array(data->map, 0);
	if (!data->map_copy)
		return (free_data_err(data, "malloc fail in loop_file() data->map"));
	data->map_height = get_arr_len(data->map);
	flood_fill_floor(data);
	flood_fill_wall(data);
	//print_str_arr(data->map_copy);
	//loop_map();
	//if (data->err != 0)
	//	return (file_error(data->err), free_data(data, 1));

	free_2d_array(data->map_copy);
	data->map_copy = NULL;
}
