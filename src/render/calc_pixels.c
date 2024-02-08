/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 17:19:40 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/08 19:55:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

typedef struct s_local_pixel
{
	int				x;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	double			wall_step;
	double			wall_y;
	mlx_texture_t	*wall_text;
}					t_pixel;

mlx_texture_t *get_wall(t_render *game, size_t x);
void	pxl_to_buffer(t_render *game, t_pixel pxl);
void	place_combined_pxl(t_render *game, mlx_texture_t wall, size_t cast_n, int wall_height);
uint32_t	pixel_from_texture(t_render *game, t_pixel pxl, size_t y);


void	calc_pixels(t_render *game)
{
	t_pixel		pxl;

	pxl.x = 0;
	while (pxl.x < WIDTH)
	{
		pxl.wall_height = (int)(HEIGHT / game->cast.distance[pxl.x]);
		pxl.wall_text = get_wall(game, pxl.x);
		pxl.wall_start = (HEIGHT / 2) - (pxl.wall_height / 2);
		pxl.wall_end = (HEIGHT / 2) + (pxl.wall_height / 2);
		if (pxl.wall_end >= HEIGHT)
			pxl.wall_end = HEIGHT - 1;
		pxl_to_buffer(game, pxl);
		pxl.x++;
	}
}

int	get_y(t_render *game, int y, t_pixel *pxl)
{
	pxl->wall_step = 1.0 * (double)PIXEL / (double)(pxl->wall_height);
	pxl->wall_y = 0;
	if (pxl->wall_start >= 0)
	{
		y = 0;
		while (y < pxl->wall_start)
		{
			mlx_put_pixel(game->text.img_walls, pxl->x, y, game->text.ceiling_color);
			y++;
		}
	}
	else
	{
		y = pxl->wall_start;
		while (y < 0)
		{
			y++;
			pxl->wall_y += pxl->wall_step;
		}
	}
	return (y);
}

void	pxl_to_buffer(t_render *game, t_pixel pxl)
{
	int y;

	y = get_y(game, 0, &pxl);
    while (y < pxl.wall_end)
    {
		mlx_put_pixel(game->text.img_walls, pxl.x, y, pixel_from_texture(game, pxl, (size_t)pxl.wall_y));
		pxl.wall_y += pxl.wall_step;
		y++;
    }
	while (y < HEIGHT - 1)
	{
		mlx_put_pixel(game->text.img_walls, pxl.x, y, game->text.floor_color);
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

uint32_t	pixel_from_texture(t_render *game, t_pixel pxl, size_t y)
{
	size_t	img_x;
	size_t	img_y;
	size_t	index;

	img_y = y;
	img_x = (int)(game->cast.wall_h[pxl.x] * PIXEL) % PIXEL;
	index = (img_y * PIXEL + img_x) * 4;
	int32_t colour = get_RGB(pxl.wall_text->pixels[index], pxl.wall_text->pixels[index + 3],\
			pxl.wall_text->pixels[index + 2], pxl.wall_text->pixels[index + 1]);
	return (colour);
}