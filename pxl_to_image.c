
#include "cubed.h"

void render(t_image *img, t_data *data)
{
	//mlx_destroy_image(data->mlx_ptr, img->img_ptr);
	color_img(img, BLUE + GREEN, WINDOW_W, WINDOW_H);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_ptr, 0, 0);
}


void create_img(t_image *img, t_data *data)
{
	img->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
	img->line_len /= 4;
	//printf("len: %zu\n", ft_strlen(mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian)));
	//printf("size of int: %lu\n", sizeof(char));
	//printf("V2: pixel bits: %d\n", img->bpp);
	//printf("V2: line_bytes: %d\n", img->line_len);
	//printf("V2: endian: %d\n", img->endian);
}

void color_img_all_colors(t_image *img, int width, int height)
{
	int y;
	int x;
	int color;

	y = 0;
	color = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
	    	img->addr[(y * img->line_len) + x] = color;
			color++; 
			
			x++;
		}
		if (color == 0)
			printf("x = %d\n", x);

		y++;
	}
	printf("V2: line_bytes: %d\n", img->line_len);
	printf("color = %d\n", color);
}

void color_img(t_image *img, int color, int width, int height)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
	    	img->addr[(y * img->line_len) + x] = color;
			x++;
		}
		y++;
	}
}


void put_pxl_to_img(t_image *img, int x, int y, int color)
{
	img->addr[(y * img->line_len) + x] = color;
}
