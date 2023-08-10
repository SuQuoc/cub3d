
#include "cubed.h"















int search_floor_ceiling(t_data *data)
{

    return (0); //couldnt set
}



  
//u have to make sure that all no,so, etc ids are the same lengths
//if passing idf is not wished
int set_texture(char *str, char *idf, t_data *data)
{
    int len;
    int i;
    char *txt_path;
    void *save_in;

    len = ft_strlen(idf);
    i = skip_is_space(str[len], len);
    
    
    int len = ft_strlen(str)
    if (str[len - 2] != '\n')
        return ; //"make sure that at end of filepath is newline"
    else
    {
        str[len - 2] = '\0':
        save_in = mlx_xpm_file_to_image(data->mlx_ptr, &str, TXT_W, TXT_H);

    }
    
    
    if (idf == NORTH)
        save_in = data->N_texture;



}




int search_texture(char *str, t_data *data)
{
    int setted;

    setted = 0;   
    if (compare_idf(str, NORTH) == 0)
        data->N_texture = set_texture(str, NORTH, data);
    else if (compare_idf(str, EAST) == 0)
        data->E_texture = set_texture(str, EAST, data);
    else if (compare_idf(str, SOUTH) == 0)
        data->S_texture =  set_texture(str, SOUTH, data);
    else if (compare_idf(str, WEST) == 0)
        data->W_texture = set_texture(str, WEST, data);
    if (data->err == )
        
    return (0); //couldnt set
}


int compare_idf(char *str, char *idf)
{
    int len;

    len = ft_strlen(idf);
    if (!str)
        return (-1);
    if (ft_strcmp(str, idf) == 0)
        return (0);
    return (1);
}

void search_idf(char *str, t_data *data)
{
    if (!str || !data)
        return ;
    if (search_texture(data) == 0)
        search_floor_ceiling(data);

}