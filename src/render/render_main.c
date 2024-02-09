/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/02/09 11:12:56 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_window(t_render *game);
void	walls_loop(void *game_data);

int	main(void)
{
	t_render	*game;

	game = init_render();
	set_window(game);
	mlx_loop_hook(game->mlx, &walls_loop, game);
	mlx_loop_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	walls_loop(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	calc_distance(game);
	calc_pixels(game);
}

/**
 * @brief inits the mlx_window
*/
void	set_window(t_render *game)
{
	if (mlx_image_to_window(game->mlx, game->text.img_walls, 0, 0) == -1)
	{
		write(2, "Error: MLX_image_to_window: walls\n", 35);
		exit (1);
	}
}
