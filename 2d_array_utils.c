
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