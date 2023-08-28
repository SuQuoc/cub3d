
#include "cubed.h"

char	**fill_arr_out(char **arr, char c, size_t max_len)
{
	char	*fill;
	char	*tmp;
	size_t	len;
	size_t	i;

	fill = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!fill || !arr)
		return (NULL);
	fill_str(fill, c, max_len);
	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len < max_len)
		{
			tmp = ft_strjoin(arr[i], &fill[len]);
			if (!tmp)
				return (free(fill), NULL);
			free(arr[i]);
			arr[i] = tmp;
		}
		i++;
	}
	return (free(fill), arr);
}

// unused yet
t_pos	find_char(char **arr, char c)
{
	t_pos	pos;

	pos.y = 0;
	while (arr[pos.y])
	{
		pos.x = 0;
		while (arr[pos.y][pos.x])
		{
			if (arr[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.y = -1;
	return (pos);
}

// returns the position in then arr if any character in find was found
t_pos	find_chars(char **arr, char *find)
{
	t_pos	pos;
	int			i;

	pos.y = 0;
	while (arr[pos.y])
	{
		pos.x = 0;
		while (arr[pos.y][pos.x])
		{
			i = 0;
			while (find[i])
			{
				if (arr[pos.y][pos.x] == find[i])
					return (pos);
				i++;
			}
			pos.x++;
		}
		pos.y++;
	}
	pos.y = -1;
	return (pos);
}
