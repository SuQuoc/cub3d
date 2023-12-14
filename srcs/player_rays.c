
#include "cubed.h"

static t_vector	calculate_camera_vector(const t_vector camera, \
							const t_vector direction, int numerator)
{
	t_vector	result;
	double		x;
	double		y;
	int			rn;

	if (RAY_NB <= 1)
		rn = 1;
	else
		rn = RAY_NB / 2;
	x = camera.x * numerator / rn;
	y = camera.y * numerator / rn;
	x += direction.x;
	y += direction.y;
	init_vector(&result, x, y);
	return (result);
}

static void	shorter_ray_correction(t_ray *ray)
{
	int	x;

	x = 1;
	if (RAY_NB < 3)
		return ;
	while (x < RAY_NB - 1)
	{
		if (ray[x - 1].shorter_ray != ray[x].shorter_ray \
			&& ray[x].shorter_ray != ray[x + 1].shorter_ray)
			ray[x].shorter_ray = ray[x - 1].shorter_ray;
		x++;
	}
}

// I hate norm
static void	outsourced_while_loop(t_data *data, t_player *player, \
									t_vector player_pos_offset)
{
	int	numerator;
	int	x;

	x = RAY_NB / 2 - 1;
	numerator = 0;
	while (x < RAY_NB)
	{
		player->ray[x].vector = calculate_camera_vector(player->camera_right, \
										player->direction, numerator);
		player->ray[x].vector = vector_multiplication(player->ray[x].vector, 2);
		dda_algorithm(data, &player->ray[x], &player_pos_offset);
		numerator++;
		x++;
	}
}

void	calculate_rays(t_data *data, t_player *player)
{
	t_vector	player_pos_offset;
	int			numerator;
	int			x;

	x = 0;
	numerator = RAY_NB / 2;
	if (data->map)
		init_vector(&player_pos_offset, get_unit_offset(data->player->pos.x), \
						get_unit_offset(data->player->pos.y));
	while (x < (RAY_NB / 2))
	{
		player->ray[x].vector = calculate_camera_vector(player->camera_left, \
										player->direction, numerator);
		player->ray[x].vector = vector_multiplication(player->ray[x].vector, 2);
		dda_algorithm(data, &player->ray[x], &player_pos_offset);
		numerator--;
		x++;
	}
	outsourced_while_loop(data, player, player_pos_offset);
	shorter_ray_correction(player->ray);
}
