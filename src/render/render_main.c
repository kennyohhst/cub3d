/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/02/16 11:47:17 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	walls_loop(void *game_data);

void	render_main(t_god *parse_data)
{
	t_render	*game;

	game = init_render(parse_data);
	if (mlx_image_to_window(game->mlx, game->text.img_backgrnd, 0, 0) == -1)
	{
		write(2, "Error\nMLX_image_to_window: walls\n", 35);
		exit(1);
	}
	mlx_loop_hook(game->mlx, &walls_loop, game);
	mlx_loop_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
	free_game(game);
}

static void	walls_loop(void *game_data)
{
	t_render	*game;

	game = (t_render *)game_data;
	calc_distance(game);
	calc_pixels(game);
}
