
#include "cubed.h"

void create_img(t_image *img, t_data *data)
{
	img->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
	//printf("len: %zu\n", ft_strlen(mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian)));
	//printf("size of int: %lu\n", sizeof(char));
	img->line_len /= 4;
	printf("V2: pixel bits: %d\n", img->bpp);
	printf("V2: line_bytes: %d\n", img->line_len);
	printf("V2: endian: %d\n", img->endian);
}


void color_img_all_colors(t_image *img, int width, int height)
{
	int y;
	int x;
	int color;

	y = 0;
	color = 600000;
	color = RED;
	x = 0;

	while (y < height)
	{
		x = 0;
/* 		if (color == 1000)
		{
			printf("color = 0\n");
			color = RED;
		} */
		//color = RED;
		while (x < width)
		{
	    	img->addr[(y * img->line_len) + x] = color;
			x++;
		}
		//printf("x = %d\n", x);
		color ++; //= 0x100000;
		y++;
	}
	//x = 0;
	//y++;
	//img->addr[(y * img->line_len) + x] = color;
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

void put_txt_to_image(t_image *img, t_image *txt, int pos_x, int pos_y)
{
	int y;
	int x;
	//printf("txt int: %d\n", txt->addr[(2 * txt->line_len) + 2]);
	//return ;
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			put_pxl_to_img(img, pos_x + x, pos_y + y, txt->addr[(y * txt->line_len) + x]);
			//printf("txt int: %d\n", txt->addr[(y * txt->line_len) + x]);
	    	//img->addr[((pos_y + y) * img->line_len) + pos_x + x] = txt->addr[(y * txt->line_len) + x];
			x++;
		}
		y++;
	}
}