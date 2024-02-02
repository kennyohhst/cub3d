/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 14:59:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/02 14:33:23 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	terminate(t_render *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	//free all struct into return
	exit(0);
}

/**
 * @todo make + and - dependant on radian
 */
static void	move_vertical(t_render *game, enum keys key)
{
	double	move;

	if (key == MLX_KEY_W)
	{
		if (game->player.rad > PI && game->player.rad < PI * 2)
			move = -1 * (double)MS;
		else
			move = (double)MS;
		if (game->map[(int)(game->player.py + move)][(int)game->player.px] != '1')
			game->player.py += move;
	}
	else
	{
		if (game->player.rad > PI && game->player.rad < PI * 2)
			move = (double)MS;
		else
			move = -1 * (double)MS;		
		if (game->map[(int)(game->player.py + move)][(int)game->player.px] != '1')
			game->player.py += move;
	}
}


/**
 * @todo make + and - dependant on radian
 */
static void	move_horizontal(t_render *game, enum keys key)
{
	double	move;

	if (key == MLX_KEY_A)
	{
		if (game->player.rad > PI / 2 && game->player.rad < 3 * PI / 2)
			move = (double)MS;
		else
			move = -1 * (double)MS;
		if (game->map[(int)game->player.py][(int)(game->player.px + move)] != '1')
			game->player.px += move;
	}
	else
	{
		if (game->player.rad > PI / 2 && game->player.rad < 3 * PI / 2)
			move = -1 * (double)MS;
		else
			move = (double)MS;
		if (game->map[(int)game->player.py][(int)(game->player.px + move)] != '1')
			game->player.px += move;
	}
}

static void	change_view(t_render *game, enum keys key)
{
	if (key == MLX_KEY_LEFT)
	{
		game->player.rad -= ROTATE;
		if (game->player.rad < 0)
			game->player.rad += 2 * PI;
	}
	else
	{
		game->player.rad += ROTATE;
		if (game->player.rad > 2 * PI)
			game->player.rad -= 2 * PI;
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
