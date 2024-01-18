/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/18 04:04:52 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void			calc_pixels(t_render *game);
void			clear_pixels(t_render *game);
void			place_pixels(t_render *game);
void 			print_pixel_data(t_render *game);

void fuck_some_shit_up(t_render *game)
{
	int32_t		*pixels;
	int32_t		rgb;

	pixels = (int32_t *)game->text.img_background->pixels;
	rgb = get_RGB(255, 255, 0, 0);

	size_t i = 0;
	while (i < 10000)
	{
		pixels[i] = rgb;
		i++;
	}
}

void	dda_main(void *game_data)
{
	t_render		*game;

	game = (t_render *)game_data;
	calc_distance(game);
	clear_pixels(game);
	calc_pixels(game);
	place_pixels(game);
	// fuck_some_shit_up(game);
	//print_pixel_data(game);
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

void 	print_pixel_data(t_render *game)
{
	size_t	i;


	printf("total_pixels: %zu\n", game->cast.total_pixels);
	i = 0;
	printf("-------------- raycasting struct data --------------\n");
	printf("[%zu]: Distance: %f, Wall_side: %i, Wall_h: %f\n", i, game->cast.distance[i], game->cast.wall_side[i], game->cast.wall_h[i]);
	printf("-------------- pixels_buffer data --------------\n");
	while (i < 128)
	{
		printf("[%zu]: %i\n", i, game->cast.pixels_buffer[i]);
		i++;
	}
	printf("-------------- placed data --------------\n");
	printf("placed pixel[0]: %i\n", game->cast.pixels_buffer[0]);
	printf("placed pixel[127]: %i\n", game->cast.pixels_buffer[127]);
	return ;
}