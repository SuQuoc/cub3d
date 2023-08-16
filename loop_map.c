
#include "cubed.h"

void	print_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
}

int nl_in_map(char *str, t_data *data)
{
    int i;

    i = 0;
    while (str[i])
    {
    	while (str[i] && str[i] != '\n')
    		i++;
    	if (str[i] && str[i] == '\n' && str[i + 1] == '\n')
    		return (data->err = ERR_NL_MAP, TRUE);
    	else if (str[i])
    		i++;
    }
    return (FALSE);
}

void set_idf_arr(char *str, int idf_arr[])
{
    if (ft_strncmp(str, NORTH, 3) == 0)
        idf_arr[0] += 1;
    else if (ft_strncmp(str, EAST, 3) == 0)
        idf_arr[1] += 1;
    else if (ft_strncmp(str, SOUTH, 3) == 0)
        idf_arr[2] += 1;
    else if (ft_strncmp(str, WEST, 3) == 0)
        idf_arr[3] += 1;
    if (ft_strncmp(str, FLOOR, 2) == 0)
        idf_arr[4] += 1;
    else if (ft_strncmp(str, CEILING, 2) == 0)
        idf_arr[5] += 1;
}

int all_idfs_found(int *arr, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (arr[i] != 1)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int idf_doubles(int *arr, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (arr[i] > 1)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

void    ft_set_zero(int *arr, int size)
{
    int	i;
    
    i = 0;
    while (i < size)
    {
    	arr[i] = 0;
    	i++;
    }
}

//checks if there are double idfs and if map content has a nl
int double_idf_or_nl_map(char *str, t_data *data)
{
	int i;
    int idf_arr[6];

    ft_set_zero(idf_arr, 6);
	i = 0;
    while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (all_idfs_found(idf_arr, 6))
			break ;
        else if (idf_doubles(idf_arr, 6))
            return (data->err = ERR_IDF_COUNT, TRUE);
		else if (is_txt_idf(&str[i]) || is_color_idf(&str[i]))
            set_idf_arr(&str[i], idf_arr);
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (nl_in_map(&str[i], data));
}
