
#include "cubed.h"

static t_vector	get_movement(t_player *player)
{
	t_vector	vector;
	int			movement_speed;

	movement_speed = TILE_SIZE / 12;
	init_vector(&vector, 0, 0);
	while (vector.x < movement_speed && vector.y < movement_speed)
	{
		player->fault -= player->slow_diff;
		if (player->fault <= 0)
		{
			player->fault += player->fast_diff;
			if (player->fast_axis == 'y')
				vector.x++;
			else
				vector.y++;
		}
		if (player->fast_axis == 'x')
			vector.x++;
		else
			vector.y++;
	}
	return (vector);
}

void	player_move_forward(t_player *player)
{
	t_vector	move;

	move = get_movement(player);
	if (player->direction.x < 0)
		move.x *= -1;
	if (player->direction.y < 0)
		move.y *= -1;
	player->pos = vector_addition(player->pos, move);
}

void	player_move_back(t_player *player)
{
	t_vector	move;

	move = get_movement(player);
	if (player->direction.x > 0)
		move.x *= -1;
	if (player->direction.y > 0)
		move.y *= -1;
	player->pos = vector_addition(player->pos, move);
}

void	player_move_right(t_player *player)
{
	t_vector	move;
	int			temp;

	move = get_movement(player);
	if (player->direction.x < 0)
		move.x *= -1;
	if (player->direction.y < 0)
		move.y *= -1;
	move.y *= -1;
	temp = move.y;
	move.y = move.x;
	move.x = temp;
	player->pos = vector_addition(player->pos, move);
}

void	player_move_left(t_player *player)
{
	t_vector	move;
	int			temp;

	move = get_movement(player);
	if (player->direction.x < 0)
		move.x *= -1;
	if (player->direction.y < 0)
		move.y *= -1;
	move.x *= -1;
	temp = move.x;
	move.x = move.y;
	move.y = temp;
	player->pos = vector_addition(player->pos, move);
}
