
#include "cubed.h"


//open ./maps/.hidden_map.cub funktioniert noch nicht ich sag einfach ohne ./ bitte
int check_extension(char const *str)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(str);
	ext_len = ft_strlen(EXTENSION);

	if (!str)
		return (1);

	if (ft_strncmp(&str[len - ext_len], EXTENSION, ext_len + 1) == 0 
		&& (str[0] != '.' || (str[0] == '.' && str[1] == '/')))
		return (0);
	//error_msg();
	ft_putstr_fd((char*)"Wrong file type/extension!\n", 2);
	//free_data(data, 1); //musste dann data weiter passen ka ob das beim tester probleme macht 
	return (1);
}
