
#include "cubed.h"

static int hidden(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.' && str[i + 1] != '.' && str[i + 1] != '/')
	{
		ft_putstr_fd((char*)"Error: Nothing hidden allowed\n", 2);
		return (TRUE);
	}
	while (str[i])
	{
		if (str[i] == '/' && str[i + 1] == '.' 
			&& str[i + 2] != '.' && str[i + 2] != '/')
		{
			ft_putstr_fd((char*)"Error: Nothing hidden allowed\n", 2);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int check_extension(char const *str)
{
	size_t len;
	size_t ext_len;
	int fd;

	if (!str)
		return (-1);
	if (hidden(str))
		return (-1);
	ext_len = ft_strlen(EXTENSION);	
	len = ft_strlen(str);
	if (len > ext_len
		&& ft_strncmp(&str[len - ext_len], EXTENSION, ext_len + 1) == 0)
		{
			fd = open(str, O_RDONLY);
			if (fd == -1)
				ft_putstr_fd((char*)"Error: failed to open file\n", 2);
			return (fd);
		}
	ft_putstr_fd((char*)"Error: Wrong file type/extension!\n", 2);
	return (-1);
}
