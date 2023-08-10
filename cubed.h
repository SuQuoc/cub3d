
# ifndef CUBED_H
# define CUBED_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#include "libft/libft.h"
//BONUS IN LIBFT AUSKLAMMMERN!!!!!!!!!!!!

#define TRUE 1
#define FALSE 0

//Error codes for input/file handling
#define ERR_TEXTURE 2
#define ERR_IDF 3
#define ERR_MAP 4

//Identifiers
#define NORTH 		"NO"
#define EAST 		"EA"
#define SOUTH 		"SO"
#define WEST 		"WE"
#define Floor 		"F"
#define Ceiling 	"C"


#define EXTENSION ".cub"

#define WINDOW_W 1920
#define WINDOW_H 1080
#define WINDOW_NAME "FORKBOMBERS"


typedef struct s_rgb
{
	int color;
	int	r;
	int g;
	int b;
}	t_rgb;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	void	*N_texture;
	void	*E_texture;
	void	*S_texture;
	void	*W_texture;

	int		err;
} t_data;


//check_extension.c
int check_extension(char const *str);

//error_msg.c
int error_msg(void);

//free_utils.c
void	free_2d_array(char **map);
void 	free_data(t_data *data, int exit_code);



int	x_window(t_data *data);

# endif
