/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2023/12/24 15:53:32 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_render	game;
	char		*set_map[] = {"11111", "10001", "10001", "10101", "10001", "10N01", "10001", "11111", ""};


	game.text.ceiling_color = (255 << 24) | (173 << 16) | (216 << 8) | 230;
	// alpha is 255(opacity), r is 173, g 216, b = 230
	game.text.floor_color = (255 << 24) | (76 << 16) | (28 << 8) | 36;
	game.map = set_map;
	run_game(game);
	return (0);
}

bool	run_game(t_render game)
{
	game.player.px = 2;
	game.player.py = 5;
	if (game.map[game.player.py][game.player.px] == 'N')
		game.player.pd = 0 * PI;
	if (game.map[game.player.py][game.player.px] == 'E')
		game.player.pd = 0.5 * PI;
	if (game.map[game.player.py][game.player.px] == 'S')
		game.player.pd = 1 * PI;
	if (game.map[game.player.py][game.player.px] == 'W')
		game.player.pd = 1.5 * PI;
	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game.mlx)
		exit(EXIT_FAILURE);

	mlx_image_t *img_floor = mlx_new_image(game.mlx, WIDTH, HEIGHT / 2);
	memset(img_floor->pixels, game.text.ceiling_color, img_floor->width * img_floor->height * BPP);

	mlx_image_t *img_ceiling = mlx_new_image(game.mlx, WIDTH, HEIGHT / 2);
	memset(img_ceiling->pixels, game.text.ceiling_color, img_ceiling->width * img_ceiling->height * BPP);
	mlx_image_to_window(game.mlx, img_floor, 0, HEIGHT / 2);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (true);
}