/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:38:00 by code              #+#    #+#             */
/*   Updated: 2024/01/18 18:05:13 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_textures(t_god **game_data)
{
	// (*game_data)->textures->t_floor = mlx_load_png((*game_data)->no_so_ea_we.we);
	(*game_data)->textures->t_floor = mlx_load_png("../textures/blue.png");
	(*game_data)->textures->i_floor = mlx_texture_to_image((*game_data)->mlx, (*game_data)->textures->t_floor);
	mlx_image_to_window((*game_data)->mlx, (*game_data)->textures->i_floor, 100, 40);
}


static void	mlx_instance(t_god **game_data)
{
	int	x;
	int	y;

	y = ft_strlen((*game_data)->full_map[0]);
	x = 0;
	while ((*game_data)->full_map[x] != NULL)
		x++;
	(*game_data)->mlx = mlx_init((y * 42), (x * 42), "cub3d", true);
	if (!(*game_data)->mlx)
		exit(write(2, "Error\nmlx instance\n", 19));
}

void	build_game(t_god **game_data)
{
	mlx_instance(game_data);
	if (!(*game_data)->mlx)
		exit(write(2, "Error\nbuild_game\n", 17));
	put_textures(game_data);
	(*game_data)->moves = 0;
}
