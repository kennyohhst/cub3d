/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 14:59:19 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/12/22 15:41:52 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_vertical(t_live_data *game, enum keys key)
{
}

static void	move_horizontal(t_live_data *game, enum keys key)
{
}

static void	change_view(t_live_data *game, enum keys key)
{
}

void	catch_keys(t_live_data *game)
{
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
