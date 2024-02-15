/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 14:59:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/15 14:23:38 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	terminate(t_render *game)
{
	mlx_close_window(game->mlx);
}

/**
 * @todo make + and - dependant on radian
 */
static void	move_vertical(t_render *game, double dir)
{
	double	movex;
	double	movey;

	movex = cos(game->player.rad) * MS * dir;
	movey = sin(game->player.rad) * MS * dir;
	if (game->map[(int)(game->player.py + movey * 1.1)][(int)(game->player.px
			+ movex * 1.1)] == '0')
	{
		game->player.px += movex;
		game->player.py += movey;
	}
}

/**
 * @todo make + and - dependant on radian
 */
static void	move_horizontal(t_render *game, double dir)
{
	double	movex;
	double	movey;

	movex = cos(game->player.rad + (PI * dir) / 2) * MS;
	movey = sin(game->player.rad + (PI * dir) / 2) * MS;
	if (game->map[(int)(game->player.py + movey * 1.1)][(int)(game->player.px
			+ movex * 1.1)] == '0')
	{
		game->player.px += movex;
		game->player.py += movey;
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
