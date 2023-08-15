
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

int no_nl_in_map(char *str)
{
	int i;
	int idf_count;

	idf_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (idf_count == 6)
		{
			while (str[i] != '\0' && str[i] != '\n')
				i++;
			if (str[i] != '\0' && str[i] == '\n' && str[i + 1] == '\n')
				return (FALSE);
		}
		else if (ft_strncmp(&str[i], NORTH, 3) == 0
			|| ft_strncmp(&str[i], EAST, 3) == 0
			|| ft_strncmp(&str[i], SOUTH, 3) == 0
			|| ft_strncmp(&str[i], WEST, 3) == 0
			|| ft_strncmp(&str[i], FLOOR, 2) == 0 
			|| ft_strncmp(&str[i], CEILING, 2) == 0)
			idf_count++;
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (TRUE);
}

//i think i can put file_error in free_data
void loop_file(int fd, t_data *data)
{
	char *map_str;

	map_str = read_map_into_str(fd);
	close(fd);
	if (!map_str)
		return (data->err = ERR_SYSTEM, free_data(data));
	if (no_nl_in_map(map_str) == FALSE)
		return (data->err = ERR_MAP, free_data(data));
	//und hier freen wurde free calls spater sparen und der check ist denke ich nicht so aufwandig 
	data->map = ft_split(map_str, '\n');
	free(map_str);
	if (!data->map)
		return (data->err = ERR_SYSTEM, free_data(data));
	loop_idf(data);
	if (data->err != 0)
		return (free_data(data));
	
	//loop_map();
	//if (data->err != 0)
	//	return (file_error(data->err), free_data(data, 1));
}
