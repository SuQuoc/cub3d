
#include "cubed.h"

int get_arr_len(char **arr)
{
    int i;

    if (!arr)
        return (0);
    i = 0;
    while (arr[i])
        i++;
    return (i);
}

char **copy_2d_array(char **old, size_t start)
{
    int i;
    char **new;
    
    i = 0;
    if (!old)
        return (NULL);
    new = malloc(sizeof(char *) * (get_arr_len(old) - start + 1));
    if (!new)
        return (NULL);
    while (old[start + i])
    {
        new[i] = ft_strdup(old[start + i]);
        if (!new)
        {
            while (i <= 0)
            {
                free(new[i]);
                i--;
            }
            return (NULL);
        }
        i++;
    }
    new[i] = NULL;
    return (new);
}
