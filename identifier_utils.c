
#include "cubed.h"

// txt=texture
int	is_txt_idf(char *str)
{
	if (ft_strncmp(str, NORTH, 3) == 0)
		return (TRUE);
	else if (ft_strncmp(str, EAST, 3) == 0)
		return (TRUE);
	else if (ft_strncmp(str, SOUTH, 3) == 0)
		return (TRUE);
	else if (ft_strncmp(str, WEST, 3) == 0)
		return (TRUE);
	return (FALSE);
}

int	is_color_idf(char *str)
{
	if (ft_strncmp(str, FLOOR, 2) == 0)
		return (TRUE);
	else if (ft_strncmp(str, CEILING, 2) == 0)
		return (TRUE);
	return (FALSE);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}