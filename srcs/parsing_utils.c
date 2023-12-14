
#include "cubed.h"

int	skip_spaces(char *str, int start)
{
	while (str[start] && str[start] == ' ')
		start++;
	return (start);
}
