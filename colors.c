#include "cubed.h"

int rgb_to_int(int r, int g, int b)
{
    return (r * 256*256) + (g * 256) + b;
}

int in_rgb_range(int n)
{
    if (-1 < n && n < 256)
        return (TRUE);
    return (FALSE);
}

void set_r_g_b(int *r, int *g, int *b, char **rgb)
{
    *r = ft_atoi(rgb[0]);
    *g = ft_atoi(rgb[1]);
    *b = ft_atoi(rgb[2]);
}

int invalid_rgb_input(char *str)
{
    int i;
    int len;

    if (!str)
        return (FALSE);
    len = 0;
    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0 && str[i] != ',')
            return (FALSE);
        if (ft_isdigit(str[i]) == 2048)
            len++;
        if (str[i] == ',')
            len = 0;
        if (len > 3 || len == 0)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int set_floor_ceiling(char *str, char *idf, t_data *data)
{
    int i;
    int r;
    int g;
    int b;
    char **rgb;
    
    i = ft_strlen(idf);
    i = skip_spaces(str, i);
    if (invalid_rgb_input(&str[i]))
        return (data->err = ERR_IDF_NORM, -1);
    rgb = ft_split(&str[i], ',');
    if (!rgb)
        return (data->err = ERR_SYSTEM, -1); //malloc
    if (get_arr_len(rgb) != 3)
        return (data->err = ERR_RGB_AMOUNT, free_2d_array(rgb), -1);
    set_r_g_b(&r, &g, &b, rgb);
    free_2d_array(rgb);
    if (in_rgb_range(r) && in_rgb_range(g) && in_rgb_range(b))
        return (rgb_to_int(r, g, b));    
    data->err = ERR_RGB_RANGE;
    return (-1);
}

int search_floor_ceiling(char *str, t_data *data)
{
    if (compare_idf(str, FLOOR) == 0)
    {
        data->floor_color = set_floor_ceiling(str, FLOOR, data);
        return (TRUE);
    }
    else if (compare_idf(str, CEILING) == 0)
    {
        data->ceil_color = set_floor_ceiling(str, CEILING, data);
        return (TRUE);
    }
    return (FALSE); //couldnt set
}
