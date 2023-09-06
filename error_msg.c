
#include "cubed.h"

// malloc read open etc is covered by perror
void	file_error(int err_code)
{
	ft_putstr_fd("Error: ", 2);
	if (err_code == ERR_SYSTEM)
		perror(NULL);
	else if (err_code == ERR_IDF)
		ft_putstr_fd("Invalid identifier!\n", 2);
	else if (err_code == ERR_IDF_COUNT)
		ft_putstr_fd("Each identifier only allowed once!\n", 2);
	else if (err_code == ERR_TEXTURE)
		ft_putstr_fd("Invalid texture path or no rights!\n", 2);
	else if (err_code == ERR_RGB_FORMAT)
		ft_putstr_fd("Invalid rgb format! Example: C 10,20,30\n", 2);
	else if (err_code == ERR_RGB_AMOUNT)
		ft_putstr_fd("Invalid amount of rgb values!\n", 2);
	else if (err_code == ERR_RGB_RANGE)
		ft_putstr_fd("Invalid rgb range!\n", 2);
	else if (err_code == ERR_MAP)
		ft_putstr_fd("Invalid map_content!\n", 2);
	else if (err_code == ERR_NL_MAP)
		ft_putstr_fd("Consecutive nl in map! Map begins when all IDF were found!\n", 2);
	else if (err_code == ERR_PL_COUNT)
		ft_putstr_fd("Invalid number of players!\n", 2);
	else if (err_code == ERR_NO_WALLS)
		ft_putstr_fd("A map need walls.\n", 2);
	return ;
}
