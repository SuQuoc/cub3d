
#include "cubed.h"

//checks if "remaing" walls are valid
int valid_wall(char **map, t_pos pos)
{
    int ht;
	int wh;

    ht = get_arr_len(map);
	wh = (int)ft_strlen(map[pos.y]);
	if ((pos.y == 0 || map[pos.y - 1][pos.x] == VOID)
		&& (pos.x == 0 || map[pos.y][pos.x - 1] == VOID)
		&& (pos.y == ht || map[pos.y + 1][pos.x] == VOID)
		&& (pos.x == wh || map[pos.y][pos.x + 1] == VOID)
		&& map[pos.y - 1][pos.x - 1] == VOID
		&& map[pos.y + 1][pos.x + 1] == VOID
		&& map[pos.y - 1][pos.x + 1 ] == VOID
		&& map[pos.y + 1][pos.x - 1] == VOID)
		return (FALSE);

	//if (ft_strchr(" \0", map[pos.y][pos.x + 1])
    //    && (pos.x == 0 || map[pos.y][pos.x - 1] == VOID)
    //    && (pos.y == 0 || pos.x > (int)ft_strlen(map[pos.y - 1])
    //        || map[pos.y - 1][pos.x] == VOID)
    //    && (pos.y == height - 1 || pos.x > (int)ft_strlen(map[pos.y + 1]) 
    //        || map[pos.y + 1][pos.x] == VOID))
    //    return (FALSE);
    if (found_left_from_pos(map[pos.y], pos.x, WALL_SUB) 
        && ft_strchr(&map[pos.y][pos.x], WALL_SUB))
            return (TRUE);
    return (FALSE);
}


//checks if the position of the player is valid
//since im already checking if theres a player i wont check again
int valid_player_pos(t_data *data)
{
	t_pos pos;
	pos = find_chars(data->map, PLAYER);
	if (surroundings_out_of_map(data->map, pos.x, pos.y, VOID))
		return (FALSE);
	if (data->map[pos.y][pos.x] == 'N')
		init_vector(&data->player->direction, pos.x, pos.y - 100);
	if (data->map[pos.y][pos.x] == 'E')
		init_vector(&data->player->direction, pos.x + 100, pos.y);
	if (data->map[pos.y][pos.x] == 'S')
		init_vector(&data->player->direction, pos.x, pos.y + 100);
	if (data->map[pos.y][pos.x] == 'W')
		init_vector(&data->player->direction, pos.x - 100, pos.y);
	data->player->pos = pos;
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
	data->map_height = get_arr_len(data->map);
	data->map_width = get_max_row_len(data->map);
	if (fill_arr_out(data->map, ' ', data->map_width) == NULL)
		free_data_err(data, "malloc failed in filling arr out");
	data->map_copy = copy_2d_array(data->map, 0);
	if (!data->map_copy)
		return (free_data_err(data, "malloc fail in loop_map()"));
	if (valid_player_pos(data) == FALSE)
		return (free_data_err(data, "Invalid player position!"));
	flood_fill_floor(data, FLOOR_CHAR, FLOOR_SUB);
	flood_fill_wall(data, WALL, WALL_SUB);
	//print_str_arr(data->map_copy);
	free_2d_array(data->map_copy);
	data->map_copy = NULL;
}