
#include "cubed.h"

int check_extension(char *str)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(str);
	ext_len = ft_strlen(EXTENSION);

	if (ft_strncmp(&str[len - ext_len], EXTENSION, ext_len + 1) == 0 && str[0] != '.')
		return (1);
	error_msg();
	ft_putstr_fd("Wrong file type (extension)!\n", 2);
	return (0);
}