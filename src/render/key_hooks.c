/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 14:59:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/09 12:41:06 by jde-baai      ########   odam.nl         */
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
static void	move_vertical(t_render *game, double dir)
{
	double	moveX;
	double	moveY;

	moveX = cos(game->player.rad) * MS * dir;
    moveY = sin(game->player.rad) * MS * dir;

    if (game->map[(int)(game->player.py + moveY + 0.05)][(int)(game->player.px + moveX + 0.05)] != '1')
    {
        game->player.px += moveX;
        game->player.py += moveY;
    }
}


/**
 * @todo make + and - dependant on radian
 */
static void	move_horizontal(t_render *game, double dir)
{
	double	moveX;
	double	moveY;

	moveX = cos(game->player.rad + (PI * dir) / 2) * MS;
    moveY = sin(game->player.rad + (PI * dir) / 2) * MS;

    if (game->map[(int)(game->player.py + moveY + 0.05)][(int)(game->player.px + moveX + 0.05)] != '1')
    {
        game->player.px += moveX;
        game->player.py += moveY;
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
void	sl_hooks(void *param)
{
	t_render	*game;

	game = (t_render *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		terminate(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_vertical(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_vertical(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_horizontal(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_horizontal(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		change_view(game, MLX_KEY_LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		change_view(game, MLX_KEY_RIGHT);
}
