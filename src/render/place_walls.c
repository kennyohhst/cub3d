/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_walls.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/08 19:43:17 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	walls_main(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	calc_distance(game);
	calc_pixels(game);
}
