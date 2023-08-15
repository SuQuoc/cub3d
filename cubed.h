
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
#define ERR_TEXTURE 		2
#define ERR_IDF 			3
#define ERR_MAP 			4
#define ERR_RGB_AMOUNT 		5
#define ERR_RGB_RANGE 		6



//Identifiers
#define TXT_W		60
#define TXT_H		60
#define NORTH 		"NO "
#define EAST 		"EA "
#define SOUTH 		"SO "
#define WEST 		"WE "
#define FLOOR 		"F "
#define CEILING 	"C "


#define EXTENSION ".cub"

#define WINDOW_W 1000
#define WINDOW_H 600
#define WINDOW_NAME "FORKBOMBERS"


typedef struct s_point
{
	char	pos_or_neg;
	char	fast_axis;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		x_diff;
	int		y_diff;
	int		fault;
}	t_point;

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
	int 	*txt_w;
	int 	*txt_h;
	int		floor_color;
	int 	ceil_color;
	int		err;
} t_data;


//check_extension.c
int check_extension(char const *str);

//draw_line.c
int	draw_line(t_data *data, t_point *point);

//init_structs.c
t_data	*init_data(void);
t_point	*init_point(int point_one_x, int point_one_y, \
						int point_two_x, int point_two_y);

//loop_file.c
int loop_file(int fd, t_data *data);
void loop_idf(t_data *data);
int loop_idf_line(char *str, t_data *data);



//identifiers.c
void *set_texture(char *str, char *idf, t_data *data);
int search_texture(char *str, t_data *data);
int compare_idf(char *str, char *idf);
void search_idf(char *str, t_data *data);



//error_msg.c
int error_msg(void);


//ft_strcmp.c
int	ft_strcmp(char *s1, char *s2);


//free_utils.c
void	free_2d_array(char **map);
void 	free_data(t_data *data, int exit_code);


//parsing_utils.c
int skip_spaces(char *str, int start);



//printing_utils.c
void	print_str_arr(char **arr);


int		x_window(t_data *data);

# endif
