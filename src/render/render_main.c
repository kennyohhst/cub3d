/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/01/05 19:38:02 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	run_game(t_render *game);

int	main(void)
{
	t_render	game;

	char *set_map[] = {"11111", "10001", "10001", "10101", "10001", "10N01",
		"10001", "11111", ""};
	game.text.ceiling_color = get_RGB(255, 173, 216, 230);
	game.text.floor_color = get_RGB(255, 76, 28, 36);
	game.map = set_map;
	run_game(&game);
	mlx_terminate(game.mlx);
	exit(EXIT_SUCCESS);
}

bool	set_background(t_render *game)
{
	int		total_pixels;
	int		half_pixels;
	int32_t	*pixels;
	int		i;

	game->text.img_background = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_background)
		return (printf("background error\n"), false);
	total_pixels = game->text.img_background->width
		* game->text.img_background->height;
	half_pixels = total_pixels / 2;
	pixels = (int32_t *)game->text.img_background->pixels;
	i = 0;
	while (i < half_pixels)
	{
		pixels[i] = game->text.ceiling_color;
		i++;
	}
	while (i < total_pixels)
	{
		pixels[i] = game->text.floor_color;
		i++;
	}
	if (mlx_image_to_window(game->mlx, game->text.img_background, 0, 0) == -1)
		return (printf("image to window error\n"), false);
	return (true);
}

bool	run_game(t_render *game)
{
	game->player.px = 2;
	game->player.py = 5;
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
	game->text.img_walls = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_walls)
		return (printf("walls error\n"), false);
	// walls to be rendered on the floor
	// function to put pixels in the image
	if (mlx_image_to_window(game->mlx, game->text.img_walls, 0, 0) == -1)
		return (printf("image to window error\n"), false);

	mlx_key_hook(game->mlx, &sl_hooks, game);
	dda_main(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (true);
}
