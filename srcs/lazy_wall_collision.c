
# include "cubed.h"

void	draw_black_image(const t_data *data)
{
	int	image_end;
	int	x;

	x = 0;
	image_end = WINDOW_H * WINDOW_W;
	while (x < image_end)
	{
		data->img->addr[x] = BLACK;
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 0, 0);
}

int	check_if_player_in_wall(const t_data *data)
{
	int	x;
	int	y;

	y = data->player->pos.y / TILE_SIZE;
	x = data->player->pos.x / TILE_SIZE;
	if (y <= 1)
		y = (data->player->pos.y - 1) / TILE_SIZE;
	if (x <= 1)
		x = (data->player->pos.x - 1) / TILE_SIZE;
	if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
		return (1);
	if (data->map[y][x] == '1' || data->map[y][x] == ' ')
		return (1);
	return (0);
}


int check_if_player_hitbox_in_wall(const t_data *data)
{
	int	x;
	int	y;

	t_vector hitbox; //as a circle
	t_vector hitpoint;
	hitbox.x = data->player->direction.x / 4;
	hitbox.y = data->player->direction.y / 4;
	
	int i = 0;
	while (i < 360 / ROTATITON_SPEED) //doesnt have to be rotation_speed (=angle)
	{
		rotate_vector_clockwise(&hitbox, data->cos, data->sin);
		hitpoint = vector_addition(data->player->pos, hitbox);
		y = hitpoint.y / TILE_SIZE;
		x = hitpoint.x / TILE_SIZE;
		if (y <= 1)
			y = (hitpoint.y - 1) / TILE_SIZE;
		if (x <= 1)
			x = (hitpoint.x - 1) / TILE_SIZE;
		if (y < 0 || y > data->map_height - 1 || x < 0 || x > data->map_width - 1)
			return (TRUE);
		if (data->map[y][x] == '1')
			return (TRUE);
		i++;
	}	
	return (FALSE);
}
