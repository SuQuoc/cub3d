
#include "cubed.h"

static double	get_ray_length(const t_vector camera, \
					const t_vector direction, int numerator)
{
	double		ray_length;
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
	x *= x;
	y *= y;
	ray_length = sqrt(x + y);
	return (ray_length);
}

void	get_ray_angles(t_player *player)
{
	double		ray_length;
	int			numerator;
	int			x;

	x = 0;
	numerator = (RAY_NB / 2);
	while (x < (RAY_NB / 2))
	{
		ray_length = get_ray_length(player->camera_left, player->direction, \
															numerator);
		player->ray[x].angle = DIRECTION_LENGTH / ray_length;
		numerator--;
		x++;
	}
	while (x < RAY_NB)
	{
		ray_length = get_ray_length(player->camera_right, player->direction, \
															numerator);
		player->ray[x].angle = DIRECTION_LENGTH / ray_length;
		numerator++;
		x++;
	}
}
