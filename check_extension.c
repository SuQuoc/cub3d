
#include "cubed.h"

int check_extension(char const *str)
{
	size_t len;
	size_t ext_len;
	
	if (!str)
		return (1);
	ext_len = ft_strlen(EXTENSION);
	//printf("ext len; %zu\n", ext_len);
	if (str[0] == '.')
	{
		ft_putstr_fd((char*)"Error: No hidden files or 'rel-rel-paths'\n", 2);
		return (1);
	}
	len = ft_strlen(str);
	if (len > ext_len
		&& ft_strncmp(&str[len - ext_len - 1], EXTENSION, ext_len + 1) == 0)
		return (0);
	ft_putstr_fd((char*)"Error: Wrong file type/extension!\n", 2);
	return (1);
}
