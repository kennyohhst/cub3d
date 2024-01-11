/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/11 18:30:56 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void			straight_lines(t_render *game, t_dda *dda);
void			calc_pixels(t_render *game);
void			clear_pixels(t_render *game);
void			place_pixels(t_render *game);

void	dda_main(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	calc_distance(game); // calculates distances,
	calc_pixels(game);
	clear_pixels(game);
	// gives all pixels in buffer empty color
	place_pixels(game);
	// places all pixels_buffer into img_walls
}



void	clear_pixels(t_render *game)
{
	size_t	i;

	i = 0;
	while (i < game->cast.total_pixels)
	{
		game->cast.pixels_buffer[i] = 0;
		i++;
	}
}

void	place_pixels(t_render *game)
{
	size_t	i;

	i = 0;
	while (i < game->cast.total_pixels)
	{
		game->text.img_walls->pixels[i] = game->cast.pixels_buffer[i];
		i++;
	}
}