
#include "cubed.h"



void put_pixel_to_img(t_image *img, int color, int width, int height)
{
	int bpp;
	int line_len;
	int endian;
	int y;
	int x;

	img->addr = (int*)mlx_get_data_addr(img, &bpp, &line_len, &endian);
	img->line_len /= 4;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
	    	img->addr[(y * line_len) + x] = color;
			x++;
		}
		y++;
	}
}	