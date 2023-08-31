
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
	//color = 0x000100;
	color = 0;
//65280
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
			color++; //= 0x100000;
			//img->addr[(y * img->line_len) + x] = intToHex(color);
			x++;
		}
		//printf("x = %d\n", x);
		//color++; //= 0x100000;
		if (color == 0)
			printf("x = %d\n", x);

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
	
	y = 0;
	while (y < TXT_SIZE)
	{
		x = 0;
		while (x < TXT_SIZE)
		{
			put_pxl_to_img(img, pos_x + x, pos_y + y, txt->addr[(y * txt->line_len) + x]);
	    	//img->addr[((pos_y + y) * img->line_len) + pos_x + x] = txt->addr[(y * txt->line_len) + x];
			x++;
		}
		y++;
	}
}

void draw_vertical_ceiling(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->ceil_color);
		start++;
	}
}

void draw_vertical_floor(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		put_pxl_to_img(data->img, x, start, data->floor_color);
		start++;
	}
}

void draw_texture(int start, int end, int x, t_data *data)
{
	while (start < end)
	{
		//printf("pxl x: %d y: %d\n", x, start);
		put_pxl_to_img(data->img, x, start, GREEN);
		start++;
	}
}

void put_txt_ray_to_image(double *ray_len, t_data *data)
{
	double bg_diff;
	double wall_h;
	int x;

	x = 0;
	while (x < RAY_NB)
	{
		wall_h = UNIT * WINDOW_H / ray_len[x];
		if (wall_h > WINDOW_H)
			wall_h = WINDOW_H;
		bg_diff = (WINDOW_H - wall_h) / 2;
		draw_vertical_ceiling(0, bg_diff, x, data);//start, end, x, data
		draw_texture(bg_diff, WINDOW_H - bg_diff, x, data);
		draw_vertical_floor(WINDOW_H - bg_diff, WINDOW_H, x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}


void paint_floor_ceiling(t_image *img, int f_color, int c_color)
{
    int x;
    int y;
     
    y = 0;
    while (y < WINDOW_H  / 2)
    {
        x = 0;
        while (x < WINDOW_W)
        {
            img->addr[(y * img->line_len) + x] = c_color;
            x++;
        }
        y++;
    }
    while (y < WINDOW_H)
    {
        x = 0;
        while (x < WINDOW_W)
        {
            img->addr[(y * img->line_len) + x] = f_color;
            x++;
        }
        y++;
    }
}
