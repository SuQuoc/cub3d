
#include "cubed.h"

int dfs(t_data *data, t_vector pos, char search, char replace)
{
    int width;

    width = ft_strlen(data->map_copy[pos.y]);
    if (pos.x < 0 || pos.x > data->map_width 
        || pos.y < 0 || pos.y >= data->map_height
        || search == replace)
        return (0);
    else if (pos.x == 0 ||
        
        ||data->map_copy[pos.y][pos.x] == ' ' 
        || data->map_copy[pos.y][pos.x] == '\0'
        || width < ft_strlen(data->map_copy[pos.y - 1])
        || width < ft_strlen(data->map_copy[pos.y + 1]))
        free_data_err(data, "Error map content");
    dfs(data, (t_vector){pos.x + 1, pos.y}, search, replace);
    dfs(data, (t_vector){pos.x + 1, pos.y - 1}, search, replace);
    dfs(data, (t_vector){pos.x, pos.y - 1}, search, replace);
    dfs(data, (t_vector){pos.x - 1, pos.y - 1}, search, replace);
    dfs(data, (t_vector){pos.x - 1, pos.y}, search, replace);
    dfs(data, (t_vector){pos.x - 1, pos.y - 1}, search, replace);
    dfs(data, (t_vector){pos.x, pos.y + 1}, search, replace);
    dfs(data, (t_vector){pos.x + 1, pos.y + 1}, search, replace);


}

