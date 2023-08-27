
#include "cubed.h"

int check_extension(char const *str)
{
	size_t len;
	size_t ext_len;
	
	if (!str)
		return (1);
	len = ft_strlen(str);
	ext_len = ft_strlen(EXTENSION);

	if (str[0] == '.' && str[1] == '/')
		str = &str[2]; 
	if (ft_strncmp(&str[len - ext_len], EXTENSION, ext_len + 1) == 0 
		&& str[0] != '.')
		return (0);
	ft_putstr_fd((char*)"Error: Wrong file type/extension!\n", 2);
	return (1);
}
