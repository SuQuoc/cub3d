
#include "cubed.h"

// only works when arr has a consistent row len
int	axis_out_of_map(char **arr, int x, int y, char c)
{
	if (y <= 0 || x <= 0)
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

// only works when arr has a consistent row len
int	diagonals_out_of_map(char **arr, int x, int y, char c)
{
	if (y <= 0 || x <= 0)
		return (TRUE);
	if (y == last_row(arr) || arr[y][x + 1] == '\0')
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

// if one surrounding is OutOfMap, including diagonals, return TRUE
int	surroundings_out_of_map(char **arr, int x, int y, char c)
{
	if (axis_out_of_map(arr, x, y, c) || diagonals_out_of_map(arr, x, y, c))
		return (TRUE);
	return (FALSE);
}
