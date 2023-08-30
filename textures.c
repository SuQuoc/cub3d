
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


//width und height scheint keinen effekt auf mlx_to_image zu haben sondern nur die file groese selbst
//printf("path of texture: %s\n", &str[i]);

void set_texture(char *str, char *idf, t_data *data, t_image *txt)
{
    int i;
    int len;

    len = ft_strlen(idf);
    i = skip_spaces(str, len);
    txt->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, &str[i], &data->txt_w, &data->txt_h);
    if (!txt->img_ptr)
    {
        data->err = ERR_TEXTURE;
        return ;
    }
    txt->addr = (int *)mlx_get_data_addr(txt->img_ptr, &txt->bpp, &txt->line_len, &txt->endian);
    txt->line_len /= 4;
    if (!txt->img_ptr)
        data->err = ERR_TEXTURE;
    printf("line len: %d\n", txt->line_len);   
    printf("txt int: %d\n", txt->addr[(2 * txt->line_len) + 2]);   
    return ;
}


int search_texture(char *str, t_data *data)
{
    int found;

    found = FALSE;
    if (ft_strncmp(str, NORTH, 3) == 0)
    {
        set_texture(str, NORTH, data, data->N_texture);
        found = TRUE;
    }    
    else if (ft_strncmp(str, EAST, 3) == 0)
    {
        set_texture(str, EAST, data, data->E_texture);
        found = TRUE;
    }
    else if (ft_strncmp(str, SOUTH, 3) == 0)
    {
        set_texture(str, SOUTH, data, data->S_texture);
        found = TRUE;
    }
    else if (ft_strncmp(str, WEST, 3) == 0)
    {
        set_texture(str, WEST, data, data->W_texture);        
        found = TRUE;
    }
    return (found);
}
