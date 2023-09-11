
#include "cubed.h"

void	set_offset_and_vert_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit)
{
	double	abs_offset_to_map;

	if (ray_hit.y < 0)
		ray_hit.y *= -1;
	abs_offset_to_map = ray_hit.y;
	if (data->player->pos.x < ray_hit.x)
	{
		(*txtr) = data->e_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % TILE_SIZE;
	}
	else
	{
		(*txtr) = data->w_texture;
		(*off_last_unit) = TILE_SIZE - ((int)(abs_offset_to_map) % TILE_SIZE);
	}
}

void	set_offset_and_hori_wall_txtr(t_vector ray_hit, t_data *data,
		t_image **txtr, double *off_last_unit)
{
	double	abs_offset_to_map;

	if (ray_hit.x < 0)
		ray_hit.x *= -1;
	abs_offset_to_map = ray_hit.x;
	if (data->player->pos.y > ray_hit.y)
	{
		(*txtr) = data->n_texture;
		(*off_last_unit) = (int)(abs_offset_to_map) % TILE_SIZE;
	}
	else
	{
		(*txtr) = data->s_texture;
		(*off_last_unit) = TILE_SIZE - (int)(abs_offset_to_map) % TILE_SIZE;
	}
}

// or normalised width coordinate
void	set_texture_and_x_pos(t_ray ray, t_data *data, t_image **txtr,
		int *x_in_txtr)
{
	double	offset_to_last_unit;

	if (ray.shorter_ray == 'x')
	{
		set_offset_and_vert_wall_txtr(ray.vector, data, txtr,
			&offset_to_last_unit);
	}
	else
		set_offset_and_hori_wall_txtr(ray.vector, data, txtr,
			&offset_to_last_unit);
	(*x_in_txtr) = (offset_to_last_unit / TILE_SIZE) * (*txtr)->line_len;
	if ((*x_in_txtr) > 0)
		(*x_in_txtr)--;
}

void	set_y_pos_of_texture(int offset_y, int wall_h, t_image *txtr,
		int *y_in_txtr)
{
	double	norm_y;
	int		y;

	norm_y = (double)offset_y / wall_h;
	y = norm_y * txtr->height;
	if (y > 63)
		y--;
	(*y_in_txtr) = (int)y * txtr->line_len;
}
