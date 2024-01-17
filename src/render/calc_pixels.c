/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:19:40 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/17 11:16:38 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_texture_t *get_wall(t_render *game, size_t cast_n);
void	place_exact_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t pixel_h, float mult_factor);
void	place_combined_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t pixel_h, float mult_factor);
uint8_t	get_texel(uint8_t a, uint8_t b, float t);

/**
 * @brief calculates the pixels to be placed in img_buffer
 * 1. Calculate the height of the wall in pixels.
2. Calculate how many pixels are needed to fill the height of the wall.
3. If the height is greater than 64 pixels,
	calculate a multiplication factor which is the height of the wall divided by 64.
4. If the height is less than 1,
	only place one pixel and don't divide the pixels.
5. If the height is greater than the pixels on screen HEIGHT,
	pixels need to be cut off. This might depend on player height.
6. Take the location of the wall hit.
7. Start taking the pixels from the texture.
8. Place them in the pixels buffer.
*/
void	calc_pixels(t_render *game)
{
	float			mult_factor;
	size_t			pixel_h; // height in pixels
	size_t			cast_n;
	mlx_texture_t	*wall;

	cast_n = 0;
	while (cast_n < WIDTH)
	{
		// pixel height + mult factor
		pixel_h = (int)(HEIGHT / game->cast.distance[cast_n]);
		if (pixel_h > HEIGHT)
			pixel_h = HEIGHT;
		else if (pixel_h < 1)
			pixel_h = 1;
		mult_factor = PIXEL / pixel_h;
		//get wall
		wall = get_wall(game, cast_n);
		// place_pixels
		if (pixel_h % PIXEL == 0)
			place_exact_pxl(game, *wall, cast_n, pixel_h, mult_factor);
		else
			place_combined_pxl(game, *wall, cast_n, pixel_h, mult_factor);
		cast_n++;
	}
}

void	place_exact_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t pixel_h, float mult_factor)
{
	size_t	i;
	size_t	img_x;
	size_t	img_y;

	i = 0;
	img_x = (int)(game->cast.wall_h[cast_n] * PIXEL) % PIXEL;
	while (i < pixel_h)
	{
		img_y = (int)(i * mult_factor);
		game->cast.pixels_buffer[cast_n * HEIGHT + i] = wall.pixels[img_y * PIXEL + img_x];
		i++;
	}
}

/**
 *
1. It calculates the x-coordinate of the pixel in the texture (img_x) based on the height of the wall hit (game->cast.wall_h[cast_n]).

2. It then enters a loop that runs for the height of the wall in pixels (pixel_h).

3. In each iteration of the loop, it calculates the y-coordinate of the pixel in the texture (img_y) based on the current pixel height and the multiplication factor (mult_factor).

4. It retrieves two texels (texel0 and texel1) from the texture. These are the texels at the calculated y-coordinate and the one just below it.

5. It calculates a fractional y-coordinate (fractional_y) which represents the exact position of the pixel within the two texels.

6. It then calls the get_texel function to interpolate between the two texels based on the fractional y-coordinate. This results in a combined texel (combined_texel).

7. Finally, it places the combined texel into the pixels_buffer at the correct position.
*/
void place_combined_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t pixel_h, float mult_factor)
{
	size_t	i;
	size_t	img_x;
	size_t	img_y;
	uint8_t	texel0;
	uint8_t	texel1;
	uint8_t	combined_texel;
	float	fractional_y;

	i = 0;
	img_x = (int)(game->cast.wall_h[cast_n] * PIXEL) % PIXEL;
	while (i < pixel_h)
	{
		img_y = (int)(i * mult_factor);
		texel0 = wall.pixels[img_y * PIXEL + img_x];
		texel1 = wall.pixels[(img_y + 1) * PIXEL + img_x];
		fractional_y = (i * mult_factor) - img_y;
		combined_texel = get_texel(texel0, texel1, fractional_y);
		game->cast.pixels_buffer[cast_n * HEIGHT + i] = combined_texel;
		i++;
	}
}

mlx_texture_t *get_wall(t_render *game, size_t cast_n)
{
	if (game->cast.wall_side[cast_n] == NORTH)
		return (game->text.t_wall_n);
	else if (game->cast.wall_side[cast_n] == EAST)
		return (game->text.t_wall_e);
	else if (game->cast.wall_side[cast_n] == SOUTH)
		return (game->text.t_wall_s);
	else
		return (game->text.t_wall_w);
}

uint8_t	get_texel(uint8_t a, uint8_t b, float t)
{
	return (a * (1 - t) + b * t);
}
