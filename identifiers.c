
#include "cubed.h"


int search_floor_ceiling(t_data *data)
{

    return (0); //couldnt set
}



  
//u have to make sure that all no,so, etc ids are the same lengths
//if passing idf is not wished
void *set_texture(char *str, char *idf, t_data *data)
{
    int i;
    int len;
    void *save_in;

    len = ft_strlen(idf);
    i = skip_is_space(str, len);
    //the thing is that u can even have files with space at end ... so dumb
    //if (is_blank(str[len - 2]))
    //{
    //    data->err = ;
    //    //"make sure that at end of filepath is newline"
    //    return ; 
    //}

    if (!str || !idf || !data)
        return (NULL);
    save_in = mlx_xpm_file_to_image(data->mlx_ptr, &str[i], TXT_W, TXT_H);
    if (!save_in)
    {
        data->err = ;
        //Both of the mistakes are same error msg and err code
        //1.
        //make sure the texture filepathname is followed by a newline 
        //if there is a white space after the name it takes the white space with it 
        //since files can be named like that 
        
        //2.
        //make sure that the path is only separated by spaces with its identifier
        //yes we know that a file can also have spaces at the beginning of the name
        //but subject says so and we dont think it should be handled
        return (NULL);
    }
    return (save_in);
}


int search_texture(char *str, t_data *data)
{
    int setted;

    setted = 0;   
    if (compare_idf(str, NORTH) == 0)
    {
        data->N_texture = set_texture(str, NORTH, data);
        setted = 1;
    }    
    else if (compare_idf(str, EAST) == 0)
    {
        data->E_texture = set_texture(str, EAST, data);
        setted = 1;
    }
    else if (compare_idf(str, SOUTH) == 0)
    {
        data->S_texture =  set_texture(str, SOUTH, data);
        setted = 1;
    }
    else if (compare_idf(str, WEST) == 0)
    {
        data->W_texture = set_texture(str, WEST, data);        
        setted = 1;
    }
    return (setted);
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
    if (search_texture(str, data) == 1)
        return ;
    if (data->err)
        return ;
    search_floor_ceiling(data);

}