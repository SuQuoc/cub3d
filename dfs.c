
#include "cubed.h"

// dfs floodfill to check if a zero touches a space
void	dfs_floor(t_data *data, t_pos pos, char search, char replace)
{
	if (data->map_copy[pos.y][pos.x] == FLOOR_SUB
		|| data->map_copy[pos.y][pos.x] == WALL || ft_strchr(PLAYER,
			data->map_copy[pos.y][pos.x]))
		return ;
	else if (surroundings_out_of_map(data->map_copy, pos.x, pos.y, VOID))
		return (free_data_err(data, "map not closed by walls!"));
	data->map_copy[pos.y][pos.x] = replace;
	dfs_floor(data, (t_pos){pos.x + 1, pos.y}, search, replace);
	dfs_floor(data, (t_pos){pos.x + 1, pos.y - 1}, search, replace);
	dfs_floor(data, (t_pos){pos.x, pos.y - 1}, search, replace);
	dfs_floor(data, (t_pos){pos.x - 1, pos.y - 1}, search, replace);
	dfs_floor(data, (t_pos){pos.x - 1, pos.y}, search, replace);
	dfs_floor(data, (t_pos){pos.x - 1, pos.y - 1}, search, replace);
	dfs_floor(data, (t_pos){pos.x, pos.y + 1}, search, replace);
	dfs_floor(data, (t_pos){pos.x + 1, pos.y + 1}, search, replace);
}

int	flood_fill_floor(t_data *data, char floor, char replace)
{
	t_pos	pos;

	pos.y = 0;
	while (data->map_copy[pos.y])
	{
		pos.x = 0;
		while (data->map_copy[pos.y][pos.x])
		{
			if (data->map_copy[pos.y][pos.x] == floor)
			{
				dfs_floor(data, pos, floor, replace);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

// dfs floodfill subing the walls out, in order to check the remaining ones
void	dfs_wall(t_data *data, t_pos pos, char search, char replace)
{
	if (pos.x < 0 || pos.y < 0 || pos.y == data->map_height
		|| data->map_copy[pos.y][pos.x] == FLOOR_SUB
		|| data->map_copy[pos.y][pos.x] == WALL_SUB
		|| data->map_copy[pos.y][pos.x] == VOID || ft_strchr(PLAYER,
			data->map_copy[pos.y][pos.x]))
		return ;
	data->map_copy[pos.y][pos.x] = replace;
	dfs_wall(data, (t_pos){pos.x + 1, pos.y}, search, replace);
	dfs_wall(data, (t_pos){pos.x, pos.y - 1}, search, replace);
	dfs_wall(data, (t_pos){pos.x - 1, pos.y}, search, replace);
	dfs_wall(data, (t_pos){pos.x, pos.y + 1}, search, replace);
}

void	dfs_all_except(t_data *data, t_pos pos, char exception, char replace)
{
	if (pos.x < 0 || pos.x == data->map_width || pos.y < 0
		|| pos.y == data->map_height || data->map_copy[pos.y][pos.x] == replace
		|| data->map_copy[pos.y][pos.x] == exception)
		return ;
	data->map_copy[pos.y][pos.x] = replace;
	dfs_all_except(data, (t_pos){pos.x + 1, pos.y}, exception, replace);
	dfs_all_except(data, (t_pos){pos.x, pos.y - 1}, exception, replace);
	dfs_all_except(data, (t_pos){pos.x - 1, pos.y}, exception, replace);
	dfs_all_except(data, (t_pos){pos.x, pos.y + 1}, exception, replace);
}

int	flood_fill_wall(t_data *data, char wall, char replace)
{
	t_pos	pos;
	int		wall_found;

	wall_found = FALSE;
	pos.y = 0;
	while (data->map_copy[pos.y])
	{
		pos.x = 0;
		while (data->map_copy[pos.y][pos.x])
		{
			if (data->map_copy[pos.y][pos.x] == wall)
			{
				if (!wall_found)
				{
					dfs_all_except(data, pos, VOID, replace);
					wall_found = TRUE;
				}
				else
					free_data_err(data,
						"Make sure theres only 1 map and no 'flying' walls!");
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
