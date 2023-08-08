
#include "cubed.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    if (check_extension(argv[1]) == 0)
        return (1);
    
    mlx_init();
    return (0);
}
