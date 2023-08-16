
#include "cubed.h"

void file_error(int err_code)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == 1) //malloc read open etc
		perror(NULL);
	else if (err_code == ERR_IDF)
		ft_putstr_fd("Invalid identifier!\n", 2);
	else if (err_code == ERR_IDF_NORM)
		ft_putstr_fd("Identifier not according to norm!\n", 2);	
	else if (err_code == ERR_IDF_COUNT)
		ft_putstr_fd("Each identifier only allowed once!\n", 2);
	else if (err_code == ERR_TEXTURE)
		ft_putstr_fd("Invalid texture path or no rights!\n", 2);
	else if (err_code == ERR_RGB_AMOUNT)
		ft_putstr_fd("Invalid amount of rgb values!\n", 2);
	else if (err_code == ERR_RGB_RANGE)
		ft_putstr_fd("Invalid rgb range!\n", 2);
	else if (err_code == ERR_MAP)
		ft_putstr_fd("Invalid map_content!\n", 2);
	else if (err_code == ERR_NL_MAP)
		ft_putstr_fd("Consecutive newline in map content!\n", 2);
	return ;
}