
#include "cubed.h"

void create_img(t_image *img, t_data *data)
{
	img->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
	img->line_len /= 4;
}

void put_pxl_to_img(t_image *img, int x, int y, int color)
{
	img->addr[(y * img->line_len) + x] = color;
}
