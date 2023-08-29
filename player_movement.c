
#include "cubed.h"

static t_vector	get_movement(t_player *player)
{
	t_vector	vector;

	init_vector(&vector, 0, 0);
	while (vector.x < MOVEMENT_SPEED && vector.y < MOVEMENT_SPEED)
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

void	player_move_forward(t_player *player, void *mlx_ptr, void *win_ptr)
{
	t_vector	move;

	move = get_movement(player);
	if (player->direction.x < 0)
		move.x *= -1;
	if (player->direction.y < 0)
		move.y *= -1;

	draw_player(player, mlx_ptr, win_ptr, BLACK);
	player->pos = vector_addition(player->pos, move);
	draw_player(player, mlx_ptr, win_ptr, RED);
}

void	player_move_back(t_player *player, void *mlx_ptr, void *win_ptr)
{
	t_vector	move;

	move = get_movement(player);
	if (player->direction.x > 0)
		move.x *= -1;
	if (player->direction.y > 0)
		move.y *= -1;

	draw_player(player, mlx_ptr, win_ptr, BLACK);
	player->pos = vector_addition(player->pos, move);
	draw_player(player, mlx_ptr, win_ptr, RED);
}

void	player_move_right(t_player *player, void *mlx_ptr, void *win_ptr)
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

	draw_player(player, mlx_ptr, win_ptr, BLACK);
	player->pos = vector_addition(player->pos, move);
	draw_player(player, mlx_ptr, win_ptr, RED);
}

void	player_move_left(t_player *player, void *mlx_ptr, void *win_ptr)
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

	draw_player(player, mlx_ptr, win_ptr, BLACK);
	player->pos = vector_addition(player->pos, move);
	draw_player(player, mlx_ptr, win_ptr, RED);
}
