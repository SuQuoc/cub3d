
#include "cubed.h"

int dfs_floor(t_data *data, t_vector pos, char search, char replace)
{
    //int width;

    //width = (int)ft_strlen(data->map_copy[pos.y]);
    if (ft_strchr("1oNESW", data->map_copy[pos.y][pos.x]))
        return (0);
    else if (pos.x <= 0 
        //|| pos.x >= width - 1 
        || pos.y <= 0 || pos.y >= data->map_height - 1 
        || data->map_copy[pos.y][pos.x] == ' '
        || data->map_copy[pos.y][pos.x] == '\n'
        || pos.x >= (int)ft_strlen(data->map_copy[pos.y - 1]) - 1
        || pos.x >= (int)ft_strlen(data->map_copy[pos.y + 1]) - 1)
        return (ft_printf("int y: %d, int x = %d\n", pos.y, pos.x), free_data_err(data, "map not closed by walls!"), 0);
    data->map_copy[pos.y][pos.x] = replace;
    dfs_floor(data, (t_vector){pos.x + 1, pos.y}, search, replace);
    dfs_floor(data, (t_vector){pos.x + 1, pos.y - 1}, search, replace);
    dfs_floor(data, (t_vector){pos.x, pos.y - 1}, search, replace);
    dfs_floor(data, (t_vector){pos.x - 1, pos.y - 1}, search, replace);
    dfs_floor(data, (t_vector){pos.x - 1, pos.y}, search, replace);
    dfs_floor(data, (t_vector){pos.x - 1, pos.y - 1}, search, replace);
    dfs_floor(data, (t_vector){pos.x, pos.y + 1}, search, replace);
    dfs_floor(data, (t_vector){pos.x + 1, pos.y + 1}, search, replace);
    return (1);
}


int flood_fill_floor(t_data *data)
{
    t_vector pos;

    pos.y = 0;
    while (data->map_copy[pos.y])
    {
        pos.x = 0;
        while (data->map_copy[pos.y][pos.x])
        {
            if (data->map_copy[pos.y][pos.x] == '0')
            {
                dfs_floor(data, pos, '0' , 'o');
                //ft_printf("flood_fill\n");
            }
            pos.x++;
        }
        pos.y++;
    }
    return (0);
}

int dfs_wall(t_data *data, t_vector pos, char search, char replace)
{

    if (pos.x < 0 || pos.y < 0 || pos.y == data->map_height
        || ft_strchr("+oNESW \n", data->map_copy[pos.y][pos.x]))
        return (0);
    data->map_copy[pos.y][pos.x] = replace;
    dfs_wall(data, (t_vector){pos.x + 1, pos.y}, search, replace);
    if (!(pos.y != 0 && pos.x >= (int)ft_strlen(data->map_copy[pos.y - 1])))
        dfs_wall(data, (t_vector){pos.x, pos.y - 1}, search, replace);
    dfs_wall(data, (t_vector){pos.x - 1, pos.y}, search, replace);
    if (!(pos.y != data->map_height && pos.x >= (int)ft_strlen(data->map_copy[pos.y + 1])))
        dfs_wall(data, (t_vector){pos.x, pos.y + 1}, search, replace);
    return (1);
}


int found_left_from_pos(char *str, int pos, char search)
{
    pos--;
    while (pos >= 0)
    {
        if (str[pos] == search)
            return (TRUE);
        pos--;
    }
    return (FALSE);
}


int valid_wall(char **map, t_vector pos)
{
    int height;

    height = get_arr_len(map);
    if (ft_strchr(" \0", map[pos.y][pos.x + 1])
        && (pos.x == 0 || map[pos.y][pos.x - 1] == ' ')
        && (pos.y == 0 || pos.x > (int)ft_strlen(map[pos.y - 1]) 
            || map[pos.y - 1][pos.x] == ' ')
        && (pos.y == height - 1 || pos.x > (int)ft_strlen(map[pos.y + 1]) 
            || map[pos.y + 1][pos.x] == ' '))
        return (FALSE);
    if (found_left_from_pos(map[pos.y], pos.x, WALL_SUB) 
        && ft_strchr(&map[pos.y][pos.x], WALL_SUB))
            return (TRUE);
    return (FALSE);

}

int flood_fill_wall(t_data *data)
{
    t_vector pos;
    int wall_found;

    wall_found = FALSE;
    pos.y = 0;
    while (data->map_copy[pos.y])
    {
        pos.x = 0;
        while (data->map_copy[pos.y][pos.x])
        {
            if (data->map_copy[pos.y][pos.x] == '1')
            {
                if (!wall_found)
                {
                    dfs_wall(data, pos, '1' , '+');
                    wall_found = TRUE;
                }
                else if (valid_wall(data->map_copy, pos) == FALSE)
                {
                    //ft_printf("int y: %d, int x = %d\n", pos.y, pos.x);
                    free_data_err(data, "Make sure theres only 1 map and no 'flying' walls!");
                }
            }
            pos.x++;
        }
        pos.y++;
    }
    return (0);
}
