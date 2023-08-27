
#include "cubed.h"

int	get_max_row_len(char **arr)
{
	int	y;
	int	len;
	int	new_len;

	if (!arr)
		return (-1);
	len = 0;
	y = 0;
	while (arr[y])
	{
		new_len = ft_strlen(arr[y]);
		if (new_len > len)
			len = new_len;
		y++;
	}
	return (len);
}

int	get_arr_len(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	last_row(char **arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = get_arr_len(arr) - 1;
	return (i);
}

char	**copy_2d_array(char **old, size_t start)
{
	int		i;
	char	**new;

	i = 0;
	if (!old)
		return (NULL);
	new = malloc(sizeof(char *) * (get_arr_len(old) - start + 1));
	if (!new)
		return (NULL);
	while (old[start + i])
	{
		new[i] = ft_strdup(old[start + i]);
		if (!new)
		{
			while (i <= 0)
			{
				free(new[i]);
				i--;
			}
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
void fill_str(char *str, char c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}

char **fill_arr_out(char **arr, char c, size_t max_len)
{
	char *fill;
	char *tmp;
	size_t len;
	size_t i;

	fill = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!fill || !arr)
		return (NULL);
	fill_str(fill, c, max_len);
	i = 0;
	while(arr[i])
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

//unused yet
t_vector	find_char(char **arr, char c)
{
	t_vector	pos;

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

//returns the position in then arr if any character in find was found 
t_vector	find_chars(char **arr, char *find)
{
	t_vector	pos;
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
