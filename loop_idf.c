
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
        {
			error_msg();
            file_error(data->err);
			//free_data(data, 1);
		    break ;
		}
        printf("Setted 1 idf i hope\n");
		i++;
	}
}

int loop_idf_line(char *str, t_data *data)
{
	if (!str || !data)
        return (1);

    if (search_texture(str, data) == TRUE)
        return (0);
	if (data->err != 0)
        return (1);
    if (search_floor_ceiling(str, data) == FALSE)
    {
        data->err = ERR_IDF;
        return (1);
    }
	return (0);
}
