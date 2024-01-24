/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/01/24 07:02:34 by julius        ########   odam.nl         */
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
	walls_main(game);
	//mlx_loop_hook(game->mlx, &walls_main, game);
	mlx_key_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	//clean_up function
	exit(EXIT_SUCCESS);
}

/**
 * @brief sets background colour and calls mlx_image_to_window
*/
void	set_windows(t_render *game)
{
	size_t		i;
	size_t		half_pixels;
	int32_t		*pixels;

	pixels = (int32_t *)game->text.img_background->pixels;
	half_pixels = (HEIGHT / 2) * WIDTH;
	i = 0;
	while (i < half_pixels)
	{
		pixels[i] = game->text.ceiling_color;
		i++;
	}
	while (i < game->cast.total_pixels)
	{
		pixels[i] = game->text.floor_color;
		i++;
	}
	if (mlx_image_to_window(game->mlx, game->text.img_background, 0, 0) == -1)
	{
		write(2, "Error: MLX_image_to_window: background\n", 40);
		exit (1);
	}
	if (mlx_image_to_window(game->mlx, game->text.img_walls, 0, 0) == -1)
	{
		write(2, "Error: MLX_image_to_window: walls\n", 35);
		exit (1);
	}
}
