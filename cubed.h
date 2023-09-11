
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
# define ERR_NO_WALLS 11

// Identifiers
# define NORTH "NO "
# define EAST "EA "
# define SOUTH "SO "
# define WEST "WE "
# define FLOOR "F "
# define CEILING "C "

// MAP
# define PLAYER "NESW"
# define MAP "10 "
# define VOID ' '
# define WALL '1'
# define WALL_SUB '+'
# define FLOOR_CHAR '0'
# define FLOOR_SUB 'o'
# define EXTENSION ".cub"

# define MAX_F_SIZE 1000000
# define WINDOW_W 1000
# define WINDOW_H 600
# define WINDOW_NAME "FORKBOMBERS"

// colors
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLACK 0x000000
# define BLUE 0x0000FF
# define RED 0xFF0000

// for raycasting
# define PI 3.141592654

# define TILE_SIZE 100
# define RAY_NB WINDOW_W
# define DIRECTION_LENGTH 100

# define ROTATITON_SPEED 2.5

typedef struct s_image
{
	void		*img_ptr;
	int			*addr;
	int			bpp;
	int			line_len;
	int			height;
	int			endian;
}				t_image;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

// hl = hypotenuse_length
typedef struct s_dda_ray
{
	double		variable_side;
	double		fixed_side;
	double		length;
	double		hl;
	double		x;
	double		y;
}				t_dda_ray;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_ray
{
	t_vector	vector;
	double		length;
	double		angle;
	char		shorter_ray;
}				t_ray;

// The rays in ray are the ray-vectors(fraction of camera) plus the direction
// The other vectors are just the respective vectors.
typedef struct s_player
{
	t_vector	pos;

	t_vector	camera_right;
	t_vector	camera_left;
	t_vector	direction;
	t_ray		*ray;
	char		fast_axis;
	int			fast_diff;
	int			slow_diff;
	int			fault;
}				t_player;

typedef struct s_line
{
	char		x_pos_or_neg;
	char		y_pos_or_neg;
	char		fast_axis;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			x_diff;
	int			y_diff;
	int			fault;
}				t_line;

typedef struct s_data
{
	t_player	*player;
	t_image		*img;

	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**map_copy;
	int			map_width;
	int			map_height;
	t_image		*n_texture;
	t_image		*e_texture;
	t_image		*s_texture;
	t_image		*w_texture;
	int			floor_color;
	int			ceil_color;
	int			err;
	double		cos;
	double		sin;
}				t_data;

// 2d_array_utils.c
int				get_arr_len(char **arr);
char			**copy_2d_array(char **old, size_t start);
int				get_max_row_len(char **arr);
int				last_row(char **arr);
int				surroundings_out_of_map(char **arr, int x, int y, char c);

// 2d_array_utils2.c
t_pos			find_chars(char **arr, char *find);
char			**fill_arr_out(char **arr, char c, size_t max_len);

// array_utils.c
void			ft_set_zero(int *arr, int size);
void			fill_str(char *str, char c, size_t len);
int				found_left_from_pos(char *str, int pos, char search);

// check_extension.c
int				check_extension(char const *str);

// colors.c
int 		search_floor_ceiling(char *str, t_data *data);

// dda_algorithm_functions.c
void	get_y_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, t_vector *pos);
void	get_x_dda_ray_length(const t_data *data, t_dda_ray *dda_ray, t_vector *pos);
void	get_x_initial_length(t_dda_ray *dda_ray, double pos_offset);
void	get_y_initial_length(t_dda_ray *dda_ray, double pos_offset);

// dda_algorithm_utils.c
double		get_segment_length(double a, double b);
double		get_unit_offset(double pos);
int			check_map_position(const t_data *data, t_dda_ray *dda_ray, t_vector *pos, char x_or_y);

// dda_algorithm.c
void			dda_algorithm(const t_data *data, t_ray *max_ray,
					t_vector *player_pos_offset);

// draw_line_utils.c
void			fast_y_xneg_yneg(const t_data *data, t_line *line,
					const int color);
void			fast_x_xneg_yneg(const t_data *data, t_line *line,
					const int color);
void			fast_x_xneg_ypos(const t_data *data, t_line *line,
					const int color);
void			fast_y_xneg_ypos(const t_data *data, t_line *line,
					const int color);

// draw_line.c
void			draw_line(const t_data *data, const t_vector start,
					const t_vector end, const int color);

// draw_map.c
void		draw_map_grid(void *mlx_ptr, void *win_ptr, int color);
void		draw_map_walls(t_data *data, char **map, int color);

// draw_map_scaled_utils.c
void	set_y_pos_of_texture(int offset_y, int wall_h, t_image *txtr,
		int *y_in_txtr);
void	set_texture_and_x_pos(t_ray ray, t_data *data, t_image **txtr,
		int *x_in_txtr);
void	set_offset_and_hori_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit);
void	set_offset_and_vert_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit);


// draw_map_scaled.c
void			put_txt_ray_to_image(t_ray *ray, t_data *data);

// dfs.c
int				flood_fill_floor(t_data *data, char floor, char replace);
int				flood_fill_wall(t_data *data, char wall, char replace);

// key_input.c
int				key_input(int keysym, t_data *data);

// error_msg.c
void			file_error(int err_code);

// free_utils.c
void			free_2d_array(char **map);
void			free_data(t_data *data);
void			free_image(t_image *img, void *mlx_ptr);

// get_ray_angles.c
void			get_ray_angles(t_player *player);

// hooks.c
int				x_window(t_data *data);
int				key_input(int keysym, t_data *data);

// identifier_utils.c
int				is_txt_idf(char *str);
int				is_color_idf(char *str);
int				rgb_to_int(int r, int g, int b);

// init_structs.c
void			init_vector(t_vector *vector, double x_position,
					double y_position);
t_data			*init_data(void);

// init_structs2.c
void			declare_base_values(t_data *data);
void			init_line(t_line *line, const t_vector start, const t_vector end);

//lazy_wall_collision.c
void			draw_black_image(const t_data *data);
int				check_if_player_in_wall(const t_data *data);


// loop_file.c
void			loop_file(int fd, t_data *data);

// loop_idf.c
void			loop_idf(t_data *data);
int				loop_idf_line(char *str, t_data *data);

// loop_map.c
int				valid_wall(char **map, t_pos pos);
void			cut_idfs_from_map(t_data *data);
void			loop_map(t_data *data);

// textures.c
int				search_texture(char *str, t_data *data);
void			set_texture(char *str, char *idf, t_data *data, t_image *txt);
void			free_data_err(t_data *data, char *error_message);

// parsing_utils.c
int				skip_spaces(char *str, int start);

// player_movement.c
void		player_move_forward(t_player *player);
void		player_move_back(t_player *player);
void		player_move_right(t_player *player);
void		player_move_left(t_player *player);

// player_rays.c
void		calculate_rays(t_data *data, t_player *player);

// player_rotations.c
void			calculate_move_values(t_player *player, int x, int y);
void			rotate_vector_clockwise(t_vector *vector, double cos,
					double sin);
void			rotate_vector_counter_clockwise(t_vector *vector, double cos,
					double sin);

// player.c
void			draw_player(t_player *player, void *mlx_ptr, void *win_ptr,
					int color);
void			draw_player_camera(t_data *data, t_player *player, int color);
void			draw_rays(t_data *data, t_player *player, int color);

// prelim_checks.c
int				prelim_checks_passed(char *str, t_data *data);

// printing_utils.c
void			print_str_arr(char **arr);
void			print_int_arr(int *arr, int size);

// pxl_to_image.c
void			create_img(t_image *img, t_data *data);
void			put_txt_to_image(t_image *img, t_image *txt, int pos_x,
					int pos_y);
void			paint_floor_ceiling(t_image *img, int f_color, int c_color);
void			render(t_image *img, t_data *data);
void			put_pxl_to_img(t_image *img, int x, int y, int color);
// void put_txt_ray_to_image(double *ray_len, t_data *data);

// vector_operations.c
t_vector	vector_multiplication(t_vector vector, int multiplier);
t_vector	vector_addition(t_vector first_addend, t_vector second_addend);
t_vector	vector_subtraction(t_vector minuend, t_vector subtrahend);

#endif