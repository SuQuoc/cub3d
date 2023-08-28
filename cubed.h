
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
# define ERR_IDF_COUNT 22
# define ERR_TEXTURE 2
# define ERR_RGB_FORMAT 4
# define ERR_RGB_AMOUNT 6
# define ERR_RGB_RANGE 7
# define ERR_MAP 5
# define ERR_NL_MAP 8
# define ERR_PL_COUNT 10

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
# define MAP "10 "

# define EXTENSION ".cub"

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

//for raycasting
//cos and sin are already point-shifted
#define COS_1 0.999847695 //<-cos(1)
#define SIN_1 0.017452406 //<-sin(1)

#define POINT_SHIFTER 65536

#define UNIT 30
#define RAY_NB 21 //needs to be uneven
#define MAX_RAY_LENGTH 200

//hl = hypotenuse_length
typedef struct s_ray
{
	double	variable_side;
	double	fixed_side;
	double	length;
	double	hl;
	double	x;
	double	y;
}	t_ray;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;


//The rays in ray are the ray-vectors(fraction of camera) plus the direction
//The other vectors are just the respective vectors.
typedef struct s_player
{
	t_vector	pos;

	t_vector	camera_right;
	t_vector	camera_left;
	t_vector	direction;
	t_vector	ray[RAY_NB];
	double		ray_length[RAY_NB];
	char		fast_axis;
	int			fast_diff;
	int			slow_diff;
	int			fault;
}	t_player;

typedef struct s_line
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
}	t_line;

typedef struct s_data
{
	t_player	*player;
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
char 		**copy_2d_array(char **old, size_t start);

// array_utils.c
void		ft_set_zero(int *arr, int size);

// check_extension.c
int			check_extension(char const *str);

// colors.c
int 		search_floor_ceiling(char *str, t_data *data);

// dda_algorithm.c
void	dda_algorithm(t_player *player, t_vector *max_ray, const char **map, long int *fp_length);

// draw_line_utils.c
void		fast_y_xneg_yneg(const t_data *data, t_line *line, const int color);
void		fast_x_xneg_yneg(const t_data *data, t_line *line, const int color);
void		fast_x_xneg_ypos(const t_data *data, t_line *line, const int color);
void		fast_y_xneg_ypos(const t_data *data, t_line *line, const int color);

// draw_line.c
void		draw_line(const t_data *data, const t_vector start, const t_vector end, const int color);

// draw_map.c
void		draw_map_grid(void *mlx_ptr, void *win_ptr, int color);
void		draw_map_walls(t_data *data, char **map, int color);


// key_input.c
int			key_input(int keysym, t_data *data);

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
void		init_vector(t_vector *vector, double x_position, double y_position);
t_data		*init_data(void);
void		init_line(t_line *line, const t_vector start, const t_vector end);

// loop_file.c
void		loop_file(int fd, t_data *data);

// loop_idf.c
void		loop_idf(t_data *data);
int			loop_idf_line(char *str, t_data *data);

// loop_map.c
void		cut_idfs_from_map(t_data *data);


// render.c
int			print_x(t_data *data);

// textures.c
int			search_texture(char *str, t_data *data);
void		*set_texture(char *str, char *idf, t_data *data);
void		free_data_err(t_data *data, char *error_message);

// render.c
int			print_x(t_data *data);

// parsing_utils.c
int			skip_spaces(char *str, int start);

// player_movement.c
void		player_move_forward(t_player *player, void *mlx_ptr, void *win_ptr);
void		player_move_back(t_player *player, void *mlx_ptr, void *win_ptr);
void		player_move_right(t_player *player, void *mlx_ptr, void *win_ptr);
void		player_move_left(t_player *player, void *mlx_ptr, void *win_ptr);

// player_rotations.c
void		calculate_move_values(t_player *player, int x, int y);
void		rotate_vector_clockwise(t_vector *vector);
void		rotate_vector_counter_clockwise(t_vector *vector);

// player.c
void		draw_player(t_player *player, void *mlx_ptr, void *win_ptr, int color);
void		draw_player_camera(t_data *data, t_player *player, int color);
void		draw_rays(t_data *data, t_player *player, int color);

// prelim_checks.c
int			prelim_checks_passed(char *str, t_data *data);

// printing_utils.c
void		print_str_arr(char **arr);
void		print_int_arr(int *arr, int size);

// vector_operations.c
t_vector	vector_multiplication(t_vector vector, int multiplier);
t_vector	vector_addition(t_vector first_addend, t_vector second_addend);
t_vector	vector_subtraction(t_vector minuend, t_vector subtrahend);
void		calculate_rays(t_player	*player, const char **map);

# endif