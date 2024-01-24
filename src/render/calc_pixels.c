/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:19:40 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/24 05:34:21 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

mlx_texture_t *get_wall(t_render *game, size_t x);
void	pxl_to_buffer(t_render *game, mlx_texture_t *wall, size_t cast_n, size_t wall_height, float mult_factor);
void	place_combined_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, size_t wall_height, float mult_factor);
uint32_t	pixel_from_texture(t_render *game, mlx_texture_t *wall, float mult_factor, size_t x, size_t y);
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
	size_t			wall_height; // height in pixels
	size_t			x;
	mlx_texture_t	*wall;

	x = 0;
	while (x < WIDTH) // WIDTH
	{
		wall_height = (int)(HEIGHT / game->cast.distance[x]);
		mult_factor = (float)PIXEL / (float)wall_height;
		wall = get_wall(game, x);
		pxl_to_buffer(game, wall, x, wall_height, mult_factor);
		x++;
	}
}

void	pxl_to_buffer(t_render *game, mlx_texture_t *wall, size_t x, size_t wall_height, float mult_factor)
{
	int y;
	int wall_start;
	int wall_end;
	wall_start = (HEIGHT - wall_height) / 2;
	if (wall_start < 0)
		wall_start = 0;
	else if (wall_start >= HEIGHT)
		wall_start = HEIGHT - 1;
	wall_end = wall_start + wall_height;
	if (wall_end < 0)
		wall_end = 0;
	else if (wall_end >= HEIGHT)
		wall_end = HEIGHT;
	y = wall_start;
    while (y < wall_end)
    {
        game->cast.pixels_buffer[y * WIDTH + x] = pixel_from_texture(game, wall, mult_factor, x, y);
		y++;
    }
}

mlx_texture_t *get_wall(t_render *game, size_t x)
{
	if (game->cast.wall_side[x] == NORTH)
		return (game->text.t_wall_n);
	else if (game->cast.wall_side[x] == EAST)
		return (game->text.t_wall_e);
	else if (game->cast.wall_side[x] == SOUTH)
		return (game->text.t_wall_s);
	else
		return (game->text.t_wall_w);
}

uint32_t	pixel_from_texture(t_render *game, mlx_texture_t *wall, float mult_factor, size_t x, size_t y)
{
	size_t	img_x;
	size_t	img_y;
	size_t	index;
	// uint8_t	texel0;
	// uint8_t	texel1;
	// uint8_t	combined_texel;
	// float	fractional_y;

	img_x = (int)(game->cast.wall_h[x] * PIXEL) % PIXEL;
	img_y = (int)(mult_factor * y) % PIXEL;

	index = (img_y * PIXEL + img_x) * 4;
	uint8_t alpha = wall->pixels[index];
	uint8_t blue = wall->pixels[index + 1];
	uint8_t green = wall->pixels[index + 2];
	uint8_t red = wall->pixels[index + 3];
	int32_t colour = get_RGB(alpha, red, green, blue);
	// texel0 = wall->pixels[img_y * PIXEL + img_x];
	// texel1 = wall->pixels[(img_y + 1) * PIXEL + img_x];
	// fractional_y = (y * mult_factor) - img_y;
	// combined_texel = get_texel(texel0, texel1, fractional_y);
	return (colour);
}