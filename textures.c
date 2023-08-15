
#include "cubed.h"

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
    save_in = mlx_xpm_file_to_image(data->mlx_ptr, &str[i], &data->txt_w, &data->txt_h);
    if (!save_in)
    {
		ft_putstr_fd("Invalid texture path!\n", 2);
        data->err = ERR_TEXTURE;
        return (NULL);
    }
    return (save_in);
}


int search_texture(char *str, t_data *data)
{
    int found;

    found = FALSE;
    if (compare_idf(str, NORTH) == 0)
    {
        data->N_texture = set_texture(str, NORTH, data);
        found = TRUE;
    }    
    else if (compare_idf(str, EAST) == 0)
    {
        data->E_texture = set_texture(str, EAST, data);
        found = TRUE;
    }
    else if (compare_idf(str, SOUTH) == 0)
    {
        data->S_texture =  set_texture(str, SOUTH, data);
        found = TRUE;
    }
    else if (compare_idf(str, WEST) == 0)
    {
        data->W_texture = set_texture(str, WEST, data);        
        found = TRUE;
    }
    return (found);
}
