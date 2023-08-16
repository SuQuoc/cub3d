
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
#define ERR_SYSTEM			1
#define ERR_TEXTURE 		2
#define ERR_IDF 			3
#define ERR_IDF_NORM 		4
#define ERR_MAP 			5
#define ERR_RGB_AMOUNT 		6
#define ERR_RGB_RANGE 		7



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

//colors
#define WHITE 0xFFFFFF
#define GREEN 0x00FF00
#define BLACK 0x000000
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
	t_player	player;
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	void	*N_texture;
	void	*E_texture;
	void	*S_texture;
	void	*W_texture;
	int 	txt_w;
	int 	txt_h;
	int		floor_color;
	int 	ceil_color;
	int		err;
} t_data;


//_player_movement.c
void	_player_move_right(t_player *player, void *mlx_ptr, void *win_ptr);
void	_player_move_left(t_player *player, void *mlx_ptr, void *win_ptr);
void	_player_move_down(t_player *player, void *mlx_ptr, void *win_ptr);
void	_player_move_up(t_player *player, void *mlx_ptr, void *win_ptr);

//_player.c
void		_draw_player(t_data *data, t_player *player);

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
void loop_file(int fd, t_data *data);

//loop_idf.c
void loop_idf(t_data *data);
int loop_idf_line(char *str, t_data *data);
int compare_idf(char *str, char *idf);

//textures.c
int search_texture(char *str, t_data *data);
void *set_texture(char *str, char *idf, t_data *data);

//colors.c
int search_floor_ceiling(char *str, t_data *data);

//error_msg.c
void file_error(int err_code);

//free_utils.c
void	free_2d_array(char **map);
void 	free_data(t_data *data);
void	free_data_err(t_data *data, char *error_message);

//ft_strcmp.c
int		ft_strcmp(char *s1, char *s2);

//parsing_utils.c
int 	skip_spaces(char *str, int start);

//printing_utils.c
void	print_str_arr(char **arr);

int		x_window(t_data *data);

//2d_array_utils.c
int 	get_arr_len(char **arr);


# endif