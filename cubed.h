
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
#define TXT_W		60
#define TXT_H		60
#define NORTH 		"NO "
#define EAST 		"EA "
#define SOUTH 		"SO "
#define WEST 		"WE "
#define Floor 		"F "
#define Ceiling 	"C "


#define EXTENSION ".cub"

#define WINDOW_W 1000
#define WINDOW_H 600
#define WINDOW_NAME "FORKBOMBERS"

//colors
#define WHITE 0xFFFFFF
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define RED 0xFF0000

typedef struct s_player
{
	int		x_pos;
	int		y_pos;
}	t_player;

typedef struct s_point
{
	char	x_pos_or_neg;
	char	y_pos_or_neg;
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

	int		err;
} t_data;

//_player.c
t_player	*init_player(int x_position, int y_position);
void	draw_player(t_data *data, t_player *player);

//check_extension.c
int		check_extension(char const *str);

//draw_line_utils.c
void	fast_y_xneg_yneg(t_data *data, t_point *point);
void	fast_x_xneg_yneg(t_data *data, t_point *point);
void	fast_x_xneg_ypos(t_data *data, t_point *point);
void	fast_y_xneg_ypos(t_data *data, t_point *point);

//draw_line.c
int		draw_line(t_data *data, t_point *point);

//init_structs.c
t_data	*init_data(void);
t_point	*init_point(int start_x, int start_y, int end_x, int end_y);

//loop_file.c
int		loop_file(int fd, t_data *data);

//error_msg.c
int		error_msg(void);

//free_utils.c
void	free_2d_array(char **map);
void	free_data(t_data *data, int exit_code);

//printing_utils.c
void	print_str_arr(char **arr);


int		x_window(t_data *data);

# endif
