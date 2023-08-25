
#include "cubed.h"

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

int	max_row_len(char **arr)
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

int	last_row(char **arr)
{
	int	i;

	if (!arr)
		return (-1);
	i = get_arr_len(arr) - 1;
	return (i);
}

int	axis_out_of_map(char **arr, int x, int y, char c)
{
	if (y == 0 || x == 0)
		return (TRUE);
	if (y == last_row(arr) || arr[y][x + 1] == '\0')
		return (TRUE);
	if (arr[y][x + 1] == c)
		return (TRUE);
	if (arr[y][x - 1] == c)
		return (TRUE);
	if (arr[y - 1][x] == c)
		return (TRUE);
	if (arr[y + 1][x] == c)
		return (TRUE);
	return (FALSE);
}

int	diagonals_out_of_map(char **arr, int x, int y, char c)
{
	if (y == 0 || x == 0)
		return (TRUE);
	if (y == last_row(arr) || arr[y][x + 1] == '\0')
		return (TRUE);
	if (x >= (int)ft_strlen(arr[y - 1]) - 1 
        || x >= (int)ft_strlen(arr[y + 1])- 1)
		return (TRUE);
	if (arr[y - 1][x + 1] == c)
		return (TRUE);
	if (arr[y - 1][x - 1] == c)
		return (TRUE);
	if (arr[y + 1][x - 1] == c)
		return (TRUE);
	if (arr[y + 1][x + 1] == c)
		return (TRUE);
	return (FALSE);
}

// including diagonals
int	surroundings_out_of_map(char **arr, int x, int y, char c)
{
	if (axis_out_of_map(arr, x, y, c) || diagonals_out_of_map(arr, x, y, c))
		return (TRUE);
	return (FALSE);
}
