
#include "cubed.h"

int	add_and_return(int add)
{
	static int	sum;

	if (!sum)
		sum = 0;
	return (sum += add);
}

static void	overflow_msg(void)
{
	ft_putstr_fd("Error\nmax file size 1 mio bytes 🤓\n", 2);
}

char	*read_map_into_str(int fd)
{
	char	*buf;
	char	*file;
	char	*temp;
	int		check;

	file = NULL;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (free(buf), free(file), NULL);
		if (check == 0)
			break ;
		if (add_and_return(check) > MAX_F_SIZE)
			return (overflow_msg(), free(buf), free(file), NULL);
		buf[check] = '\0';
		temp = ft_strmerge(file, buf);
		if (!temp)
			return (free(buf), free(file), NULL);
		file = temp;
	}
	return (free(buf), file);
}

void	loop_file(int fd, t_data *data)
{
	char	*map_str;

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
	loop_map(data);
}
