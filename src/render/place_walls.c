/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_walls.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/08 18:18:00 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			clear_buffer(t_render *game);
void			place_pixels(t_render *game);
void 			print_pixel_data(t_render *game);

void	walls_main(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	clear_buffer(game);
	calc_distance(game);
	calc_pixels(game);
	place_pixels(game);
}

void	clear_buffer(t_render *game)
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
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_put_pixel(game->text.img_walls, x, y, game->cast.pixels_buffer[y * WIDTH + x]);
			y++;
		}
		x++;
	}
}
