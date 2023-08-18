
#ifndef CUBED_H
# define CUBED_H

# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
// BONUS IN LIBFT AUSKLAMMMERN!!!!!!!!!!!!

# define TRUE 1
# define FALSE 0

// Error codes for input/file handling
# define ERR_SYSTEM 1
# define ERR_IDF 3
# define ERR_IDF_NORM 4
# define ERR_IDF_COUNT 22
# define ERR_TEXTURE 2
# define ERR_RGB_AMOUNT 6
# define ERR_RGB_RANGE 7
# define ERR_MAP 5
# define ERR_NL_MAP 8

// Identifiers
# define TXT_W 60
# define TXT_H 60
# define NORTH "NO "
# define EAST "EA "
# define SOUTH "SO "
# define WEST "WE "
# define FLOOR "F "
# define CEILING "C "

// MAP
# define PLAYER "NESW"

# define EXTENSION ".cub"

# define WINDOW_W 1000
# define WINDOW_H 600
# define WINDOW_NAME "FORKBOMBERS"

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
}			t_point;

typedef struct s_rgb
{
	int		color;
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	char	**map;
	void	*N_texture;
	void	*E_texture;
	void	*S_texture;
	void	*W_texture;
	int		txt_w;
	int		txt_h;
	int		floor_color;
	int		ceil_color;
	int		err;
}			t_data;

// 2d_array_utils.c
int			get_arr_len(char **arr);

// check_extension.c
int			check_extension(char const *str);

// colors.c
int			search_floor_ceiling(char *str, t_data *data);

// draw_line_utils.c
void		fast_y_xneg_yneg(t_data *data, t_point *point);
void		fast_x_xneg_yneg(t_data *data, t_point *point);
void		fast_x_xneg_ypos(t_data *data, t_point *point);
void		fast_y_xneg_ypos(t_data *data, t_point *point);

// draw_line.c
int			draw_line(t_data *data, t_point *point);

// error_msg.c
void		file_error(int err_code);

// free_utils.c
void		free_2d_array(char **map);
void		free_data(t_data *data);

// ft_strcmp.c
int			ft_strcmp(char *s1, char *s2);

// hooks.c
int			x_window(t_data *data);
int			key_input(int keysym, t_data *data);

// identifier_utils.c
int			is_txt_idf(char *str);
int			is_color_idf(char *str);

// init_structs.c
t_data		*init_data(void);
t_point		*init_point(int start_x, int start_y, int end_x, int end_y);

// loop_file.c
int			double_idf_or_nl_map(char *str, t_data *data);

// loop_idf.c
void		loop_file(int fd, t_data *data);
void		loop_idf(t_data *data);
int			loop_idf_line(char *str, t_data *data);

// loop_map.c
int			nl_in_map(char *str, t_data *data);

// render.c
int			print_x(t_data *data);

// textures.c
int			search_texture(char *str, t_data *data);
void		*set_texture(char *str, char *idf, t_data *data);

// MLX RELATED_______________________________________
// render.c
int			print_x(t_data *data);

// parsing_utils.c
int			skip_spaces(char *str, int start);

// printing_utils.c
void		print_str_arr(char **arr);
void		print_int_arr(int *arr, int size);

#endif
