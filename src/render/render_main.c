/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/01/10 15:37:40 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	run_game(t_render *game);
void	set_windows(t_render *game);

int	main(void)
{
	t_render	*game;

	game = init_render(game);
	set_windows(game);
	mlx_loop_hook(game->mlx, &dda_main, game);
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
	int		half_pixels;
	int		i;
	
	half_pixels = game->cast.total_pixels / 2;
	i = 0;
	while (i < half_pixels)
	{
		game->text.img_background->pixels[i] = game->text.ceiling_color;
		i++;
	}
	while (i < game->cast.total_pixels)
	{
		game->text.img_background->pixels[i] = game->text.floor_color;
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

bool	run_game(t_render *game)
{

	if (game->map[game->player.py][game->player.px] == 'N')
		game->player.rad = 0 * PI;
	if (game->map[game->player.py][game->player.px] == 'E')
		game->player.rad = 0.5 * PI;
	if (game->map[game->player.py][game->player.px] == 'S')
		game->player.rad = 1 * PI;
	if (game->map[game->player.py][game->player.px] == 'W')
		game->player.rad = 1.5 * PI;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	set_background(game);
	mlx_key_hook(game->mlx, &sl_hooks, game);
	mlx_loop_hook(game->mlx, &dda_main, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (true);
}
