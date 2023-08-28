
#include "cubed.h"

void	ft_set_zero(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void	fill_str(char *str, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}

int found_left_from_pos(char *str, int pos, char search)
{
    pos--;
    while (pos >= 0)
    {
        if (str[pos] == search)
            return (TRUE);
        pos--;
    }
    return (FALSE);
}