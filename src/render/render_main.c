/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/02/08 19:43:28 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	run_game(t_render *game);
void	set_windows(t_render *game);

int	main(void)
{
	t_render	*game;

	game = init_render();
	printf("PI=%f\n", PI);
	printf("init done\n");
	set_windows(game);
	printf("set windows done\n");
	mlx_loop_hook(game->mlx, &walls_main, game);
	mlx_loop_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

/**
 * @brief sets background colour and calls mlx_image_to_window
*/
void	set_windows(t_render *game)
{
	if (mlx_image_to_window(game->mlx, game->text.img_walls, 0, 0) == -1)
	{
		write(2, "Error: MLX_image_to_window: walls\n", 35);
		exit (1);
	}
}
