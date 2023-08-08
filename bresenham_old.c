
//t_point WURDE IN FDF VERWENDET
//

typedef struct s_bresenham_var
{
	int				err;
	int				err2;
	int				dx;
	int				dy;
	int				step_x;
	int				step_y;
}					t_bresenham_var;


typedef struct s_point
{
	int				x;
	int				y;
}					t_point;



int	returnstep(int d0, int d1)
{
	int	delta;

	delta = d1 - d0;
	if (delta > 0)
		return (1);
	if (delta < 0)
		return (-1);
	return (0);
}

void	drawline(t_point P0, t_point P1, t_data data, int color)
{
	t_bresenham_var	line;

	line.step_x = returnstep(P0.x, P1.x);
	line.step_y = returnstep(P0.y, P1.y);
	line.dx = abs(P1.x - P0.x);
	line.dy = -abs(P1.y - P0.y);
	line.err = line.dx + line.dy;
	while (P0.x != P1.x || P0.y != P1.y)
	{
		line.err2 = 2 * line.err;
		if (line.err2 > line.dy)
		{
			line.err += line.dy;
			P0.x += line.step_x;
		}
		if (line.err2 < line.dx)
		{
			line.err += line.dx;
			P0.y += line.step_y;
		}
		if (IMG_HEIGHT > P0.y && P0.y > 0 && 0 < P0.x && P0.x < IMG_WIDTH)
			my_mlx_pixel_put(&data.img, P0.x, P0.y, color);
	}
}