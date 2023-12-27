/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 14:59:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/12/27 15:05:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	terminate(t_render *game)
{
	mlx_close_window(game->mlx);
	exit(0);
}

/**
 * @note update to check for wall collision
 */
static void	move_vertical(t_render *game, enum keys key)
{
	if (key == MLX_KEY_W)
		game->player.py -= MS;
	else
		game->player.py += MS;
}

/**
 * @note update to check for wall collision
 */
static void	move_horizontal(t_render *game, enum keys key)
{
	if (key == MLX_KEY_A)
		game->player.px -= MS;
	else
		game->player.px += MS;
}

static void	change_view(t_render *game, enum keys key)
{
	if (key == MLX_KEY_LEFT)
	{
		game->player.pd -= ROTATE;
		if (game->player.pd < 0)
			game->player.pd += 2 * PI;
	}
	else
	{
		game->player.pd += ROTATE;
		if (game->player.pd > 2 * PI)
			game->player.pd -= 2 * PI;
	}
}

/**
 * @note program segfaults when pressing cross button
 */
void	sl_hooks(mlx_key_data_t keydata, void *param)
{
	t_render	*game;

	(void)keydata;
	game = (t_render *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		terminate(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_vertical(game, MLX_KEY_W);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_vertical(game, MLX_KEY_S);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_horizontal(game, MLX_KEY_A);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_horizontal(game, MLX_KEY_D);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		change_view(game, MLX_KEY_LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		change_view(game, MLX_KEY_RIGHT);
}
