
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

int set_floor_ceiling(char *str, char *idf, t_data *data)
{
    int i;
    int r;
    int g;
    int b;
    char **rgb;

    i = ft_strlen(idf);
    i = skip_spaces(str, i);
    rgb = ft_split(&str[i], ',');
    if (!rgb)
        return (-1); //malloc
    if (get_arr_len(rgb) != 3)
        return (data->err = ERR_RGB_AMOUNT, -1);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    free_2d_array(rgb);
    if (in_rgb_range(r) && in_rgb_range(g) && in_rgb_range(b))
        return (rgb_to_int(r, g, b));    
    data->err = ERR_RGB_RANGE;
    return (-1);
}


int search_floor_ceiling(char *str, t_data *data)
{
    int r;
    int g;
    int b;
    
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



  
//u have to make sure that all no,so, etc ids are the same lengths
//if passing idf is not wished
    //the thing is that u can even have files with space at end ... so dumb
    //if (is_blank(str[len - 2]))
    //{
    //    data->err = ;
    //    //"make sure that at end of filepath is newline"
    //    return ; 
    //}
        //Both of the mistakes are same error msg and err code
        //1.
        //make sure the texture filepathname is followed by a newline 
        //if there is a white space after the name it takes the white space with it 
        //since files can be named like that 
        
        //2.
        //make sure that the path is only separated by spaces with its identifier
        //yes we know that a file can also have spaces at the beginning of the name
        //but subject says so and we dont think it should be handled
void *set_texture(char *str, char *idf, t_data *data)
{
    int i;
    int len;
    void *save_in;

    if (!str || !idf || !data)
        return (NULL);
    len = ft_strlen(idf);
    i = skip_spaces(str, len);
    //printf("path of texture: %s\n", &str[i]);
    //width und height scheint keinen effekt zu haben sondern nur die file groese selbst
    save_in = mlx_xpm_file_to_image(data->mlx_ptr, &str[i], data->txt_w, data->txt_h);
    if (!save_in)
    {
        printf("smth wnet wrong with file to image\n");
        data->err = ERR_TEXTURE;
        return (NULL);
    }
    printf("Some texture got set by set_texture\n");
    return (save_in);
}


int search_texture(char *str, t_data *data)
{
    int found;

    found = FALSE;
    if (compare_idf(str, NORTH) == 0)
    {
        printf("found north\n");
        data->N_texture = set_texture(str, NORTH, data);
        found = TRUE;
    }    
    else if (compare_idf(str, EAST) == 0)
    {
        printf("found east\n");
        data->E_texture = set_texture(str, EAST, data);
        found = TRUE;
    }
    else if (compare_idf(str, SOUTH) == 0)
    {
        printf("found south\n");
        data->S_texture =  set_texture(str, SOUTH, data);
        found = TRUE;
    }
    else if (compare_idf(str, WEST) == 0)
    {
        printf("found south\n");
        data->W_texture = set_texture(str, WEST, data);        
        found = TRUE;
    }
    return (found);
}


int compare_idf(char *str, char *idf)
{
    if (!str)
        return (-1);
    if (ft_strncmp(str, idf, ft_strlen(idf)) == 0)
        return (0);
    return (1);
}

void search_idf(char *str, t_data *data)
{
    if (!str || !data)
        return ;
    if (search_texture(str, data) == TRUE)
        return ;
    //search_floor_ceiling(data);
}