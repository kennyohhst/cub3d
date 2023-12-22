/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:13:57 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2023/12/22 17:33:46 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_render	game;

	char *set_map[] = {"11111", "10001", "10001", "10101", "10001", "10N01",
		"10001", "11111", ""};
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

	// data->mlx = mlx_init();
	// if (!data->mlx)
	// 	return (false);
	// data->textures = init_textures(data->mlx);
	// if (!data->textures)
	// 	return (false);
	// data->collectables = 0;
	// data->moves = 0;
	// data->p_x = data->map->player_x;
	// data->p_y = data->map->player_y;
	// if (!render(data))
	// 	return (false);
	// mlx_hook(data->mlx->window, 2, 1L << 0, key_press, data);
	// mlx_hook(data->mlx->window, 17, 1L << 17, close_window, data);
	// mlx_loop(data->mlx->mlx);
	return (true);
}