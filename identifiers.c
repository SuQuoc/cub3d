
#include "cubed.h"


int set_texture(char *str, char *idf, t_data *data)
{
    int i;

    i = ft_strlen(idf);
    i = skip_is_blank(str[i], i);
}



int search_floor_ceiling(t_data *data)
{

    return (0); //couldnt set
}








int search_texture(char *str, t_data *data)
{
    //all idfs should be in the beginning of the str -> somewhere i skip all the spaces before
    if (compare_idf(str, NORTH))
        set_texture(str, NORTH, data);
    else if (compare_idf(str, EAST))
        set_texture(str, EAST, data);
    else if (compare_idf(str, SOUTH))
        set_texture(str, SOUTH, data);
    else if (compare_idf(str, WEST))
        set_texture(str, WEST, data);
    return (0); //couldnt set
}


int compare_idf(char *str, char *idf)
{
    if (!str)
        return (-1);
    if (ft_strncmp(str, idf, 2) == 0 && is_blank(str[2]))
        return (1);
    return (0);
}

void search_idf(char *str, t_data *data)
{
    if (!str || !data)
        return ;
    if (search_texture(data) == 0)
        search_floor_ceiling(data);

}