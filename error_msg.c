
#include "cubed.h"

int error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void file_error(int err_code)
{
	if (err_code == 1) //malloc read open etc
		perror(NULL);
	if (err_code == ERR_TEXTURE)
		return ;
	else if (err_code == ERR_IDF)
		return ;
	else if (err_code == ERR_MAP)
		return ;
	return ;
}