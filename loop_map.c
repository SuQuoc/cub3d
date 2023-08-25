
#include "cubed.h"

//since im already checking if theres a plyer i wont check again
int valid_player_pos(t_data *data)
{
	t_vector pos;

	pos = find_chars(data->map, PLAYER);
	if (surroundings_out_of_map(data->map, pos.x, pos.y, ' '))
		return (FALSE);
	return (TRUE);
}

void cut_idfs_from_map(t_data *data)
{
	char **tmp;

	tmp = data->map;
	data->map = copy_2d_array(data->map, 6);
	free_2d_array(tmp);
	if (!data->map)
		return(data->err = ERR_SYSTEM, free_data(data));
}

void loop_map(t_data *data)
{
	cut_idfs_from_map(data);
	data->map_copy = copy_2d_array(data->map, 0);
	if (!data->map_copy)
		return (free_data_err(data, "malloc fail in loop_map()"));
	data->map_height = get_arr_len(data->map);
	if (valid_player_pos(data) == FALSE)
		return (free_data_err(data, "Invalid player position!"));
	flood_fill_floor(data);
	flood_fill_wall(data);
	//print_str_arr(data->map_copy);
	free_2d_array(data->map_copy);
	data->map_copy = NULL;
}