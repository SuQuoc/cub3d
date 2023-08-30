
#include "cubed.h"

void loop_idf(t_data *data)
{
	int i;

	i = 0;
	if (!data->map)
		return ;
	while (data->map[i] && i < 6)
	{
		if (loop_idf_line(data->map[i], data) == 1)
		    break ;
		if (data->err != 0)
			break ;
		i++;
	}
}

int loop_idf_line(char *str, t_data *data)
{
    if (search_texture(str, data) == TRUE)
        return (0);
	else if (data->err != 0)
        return (1);
	if (search_floor_ceiling(str, data) == FALSE)
    {
        data->err = ERR_IDF;
        return (1);
    }
	return (0);
}
