
#include "cubed.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || s1 == NULL || !s2 || s2 == NULL)
		return (9999);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}