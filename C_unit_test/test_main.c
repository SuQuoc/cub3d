
# include "unit_tests.h"

void ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_data(data);
}


int main()
{  
    t_data *g_data = init_data();
    ft_mlx_init(g_data);

    //identifier_tests
    char identifier_tests [][2][1000] = 
    {
        {"different_identifier_order.cub" , "Error message"},
        {"different_.cub" , "Error message"},
        {"different_.cub" , "Error message"},
        {"different_.cub" , "Error message"},
        NULL,
    };
    int nbr = sizeof(identifier_tests) / sizeof(identifier_tests[0]);
    
    test_framework("maps/identifier_tests/", (char***)identifier_tests, g_data);



    while (waitpid(-1, NULL, WUNTRACED) != -1)
        ;
    return 0;
}
