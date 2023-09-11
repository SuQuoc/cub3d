
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
			while (i >= 0)
			{
				free(new[i]);
				i--;
			}
			return (free(new), NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
