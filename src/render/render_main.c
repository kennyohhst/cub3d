/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/02/10 18:33:36 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_window(t_render *game);
void	walls_loop(void *game_data);


void	render_main(t_god *parse_data)
{
	t_render	*game;

	(void)parse_data;
	game = init_render();
	if (mlx_image_to_window(game->mlx, game->text.img_backgrnd, 0, 0) == -1)
	{
		write(2, "Error: MLX_image_to_window: walls\n", 35);
		exit (1);
	}
	mlx_loop_hook(game->mlx, &walls_loop, game);
	mlx_loop_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
}

void	walls_loop(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	calc_distance(game);
	calc_pixels(game);
}

// int	main(void)
// {
// 	t_god *data = NULL;
// 	render_main(data);
// 	return(0);
// }
