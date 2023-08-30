
#include "cubed.h"

int	make_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (data->win_ptr == NULL)
		free_data(data);
	return (0);
}

void ft_mlx_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_data(data);
}
//static void texture_test(t_data *data)
//{
//	int pixel_bits;
//	int line_bytes;
//	int endian;
//	char *buffer = mlx_get_data_addr(data->E_texture, &pixel_bits, &line_bytes, &endian);
//	(void)buffer;
//	printf("pixel bits: %d\n", pixel_bits);
//	printf("line_bytes: %d\n", line_bytes);
//	printf("endian: %d\n", endian);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->E_texture, 100, 100);
//
//	usleep(10000);
//	data->img.img_ptr = mlx_new_image(data->mlx_ptr, 100, 100);
//	manipulate_img(data->img.img_ptr, RED);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
//}

int main(int argc, char **argv)
{
	t_data *data;
	int fd;

	if (argc != 2)
		return (1);
	fd = check_extension(argv[1]);
	if (fd == -1)
		return (1);
	data = init_data(); 
	ft_mlx_init(data); //100k	
	loop_file(fd, data); //3k
	make_window(data); //10k
	
	create_img(data->img, data);
	color_img(data->img, BLUE, WINDOW_W, WINDOW_H);
	put_txt_to_image(data->img, data->S_texture, 100, 100);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	//color_img_all_colors(data->img, WINDOW_W, WINDOW_H);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);

	draw_map_grid(data->mlx_ptr, data->win_ptr, WHITE);
	draw_map_walls(data, data->map, WHITE);
	calculate_rays(data, data->player);

	//mlx_loop_hook(data->mlx_ptr, &print_x, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_input, data);
	mlx_hook(data->win_ptr, 17, 0, x_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
