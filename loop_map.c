
#include "cubed.h"


void cut_idfs_from_map(t_data *data)
{
	char **tmp;

	tmp = data->map;
	data->map = copy_2d_array(data->map, 6);
	free_2d_array(tmp);
	if (!data->map)
		return(data->err = ERR_SYSTEM, free_data(data));
}

