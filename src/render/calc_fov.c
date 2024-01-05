/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/05 13:22:30 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

typedef struct s_raycasting
{
	int			rayx;
	int			rayy;
	int			stepx;
	int			stepy;
	double		ray_steps;
	double *distance;       // distance from player to wall per ray (euclidean)
	int *wall_side;         // 1 = north, 2 = east, 3 = south, 4 = west per ray
	double *wall_h;         // exact value of where wall was hit per ray 0.0
	int32_t *pixels_buffer; // pixels to be placed in img_walls
}				t_raycasting;

/**
 * @param cast_n is the current ray
 * @param radian is the current radian
 * @param mapx is x coordinate of the wall that was hit
 * @param mapy is y coordinate of the wall that was hit
 * @param wall_h is the exact value of where the wall was hit 0.0 - 1.0
 * @param wall_side is the side of the wall that was hit - NORTH, EAST, SOUTH,
	WEST
 * @param stepx is the step in x direction
 * @param stepy is the step in y direction
 * @param sidedistx is the distance to the next x side
 * @param sidedisty is the distance to the next y side
 */
typedef struct s_local_dda
{
	size_t		cast_n;
	double		radian;
	int			mapx;
	int			mapy;
	double wall_h; // exact value of where wall was hit
	int			wall_side;
	double		stepx;
	double		stepy;
	double		sidedistx;
	double		sidedisty;
}				t_dda;

// to do image rezier in place pixels -> also amount of pixels horizontally
// based on the height of the pixel and the height of the textured	image(64x64)

void			calc_dda(t_render *game, t_raycasting *cast, t_dda *dda);
void			calc_distance(t_render *game, t_raycasting *cast, t_dda dda);
bool			calculations(t_render *game, t_raycasting *dda);
void			straight_lines(t_render *game, t_raycasting *cast, t_dda *dda);
void			calc_pixels(t_render *game, t_raycasting *cast);

t_raycasting	*init_cast(void)
{
	t_raycasting	*cast;

	cast = ft_calloc(sizeof(t_raycasting), 1);
	cast->distance = malloc(sizeof(double) * WIDTH);
	cast->wall_side = malloc(sizeof(int) * WIDTH);
	cast->wall_h = malloc(sizeof(double) * WIDTH);
	cast->ray_steps = FOV / WIDTH;
	return (cast);
}

bool	dda_main(t_render *game)
{
	t_raycasting	*cast;
	size_t			total_pixels;

	cast = init_cast();
	total_pixels = game->text.img_walls->width * game->text.img_walls->height;
	calculations(game, cast); // calculates distances,
	//intersections and wall_side calc_pixels(game, cast);
	// places pixels calculated into pixels_buffer
	clear_pixels(game);
	// gives all pixels in img_walls empty color
	place_pixels(game, cast);
	// places pixels_buffer into img_walls
	cast->rayx = (int)game->player.px;
	cast->rayy = (int)game->player.py;
}

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
void	calc_pixels(t_render *game, t_raycasting *cast)
{
	int height; // height in pixels
				// function needs to calculate the height of the wall in pixels
				// calculate how many pixels are needed to fill the height of the wall
				// if the height is greater than 64 pixels,
//a multiplicatoin factor needs to be caluclated
		// the multiplication factor is the height of the wall divided by 64
		// if the height is less than 1 only place one pixel and dont div the pixels
		// if the height is greater than the pixels on screen HEIGHT,
	//	pixels need to be cut off->depending on player height
	//	?
	// take the location of the wall hit
	// start taking the pixels from the texture
	// place them in the pixels buffer
}

bool	calculations(t_render *game, t_raycasting *cast)
{
	t_dda	dda;

	dda.radian = game->player.rad - (FOV / 2);
	dda.cast_n = 0;
	dda.sidedistx = -1;
	dda.sidedisty = -1;
	dda.mapx = (int)game->player.px;
	dda.mapy = (int)game->player.py;
	while (dda.cast_n < WIDTH)
	{
		calc_dda(game, cast, &dda);
		cast->wall_h[dda.cast_n] = dda.wall_h;
		calc_distance(game, cast, dda);
		dda.radian += cast->ray_steps;
		dda.cast_n++;
	}
}

/**
 * @brief sets wallx, wally, wall_hit and wall_side
 */
void	calc_dda(t_render *game, t_raycasting *cast, t_dda *dda)
{
	double	deltaX;
	double	deltaY;

	if (dda->radian == 0 || dda->radian == 0.5 * PI || dda->radian == PI
		|| dda->radian == 1.5 * PI)
		straight_lines(game, cast, dda);
	deltaX = fabs(1 / cos(dda->radian));
	deltaY = fabs(1 / sin(dda->radian));
	// calculate step and initial sideDist
	if (cos(dda->radian) < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (game->player.px - dda->mapx) * deltaX;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1.0 - game->player.px) * deltaX;
	}
	if (sin(dda->radian) < 0)
	{
		dda->stepy = -1;
		dda->sidedisty = (game->player.py - dda->mapy) * deltaY;
	}
	else
	{
		dda->stepy = 1;
		dda->sidedisty = (dda->mapy + 1.0 - game->player.py) * deltaY;
	}
	// actual DDA
	while (1)
	{
		// jump to next map square in x or y direction
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += deltaX;
			dda->mapx += dda->stepx;
		}
		else
		{
			dda->sidedisty += deltaY;
			dda->mapy += dda->stepy;
		}
		// check if ray has hit a wall
		if (game->map[dda->mapy][dda->mapx] > 0)
		{
			if (dda->sidedistx < dda->sidedisty)
			{
				if (dda->stepx == -1)
					dda->wall_side = WEST;
				else
					dda->wall_side = EAST;
				dda->wall_h = dda->mapx - (int)dda->mapx;
			}
			else
			{
				if (dda->stepy == -1)
					dda->wall_side = SOUTH;
				else
					dda->wall_side = NORTH;
				dda->wall_h = dda->mapy - (int)dda->mapy;
			}
			break ;
		}
	}
}

void	straight_lines(t_render *game, t_raycasting *cast, t_dda *dda)
{
	if (dda->radian == 0)
	{
		while (game->map[dda->mapy][dda->mapx] != '1')
		{
			dda->mapy--;
		}
		dda->sidedisty = fabs(game->player.py - dda->mapy);
		dda->wall_side = SOUTH;
		dda->wall_h = game->player.py - (int)game->player.py;
	}
	if (game->player.rad = 1 * PI)
	{
		while (game->map[dda->mapy][dda->mapx] != '1')
		{
			dda->mapy++;
		}
		dda->sidedisty = fabs(game->player.py - dda->mapy);
		dda->wall_side = NORTH;
		dda->wall_h = game->player.py - (int)game->player.py;
	}
	if (game->player.rad = 0.5 * PI)
	{
		while (game->map[dda->mapy][dda->mapx] != '1')
		{
			dda->mapx++;
		}
		dda->sidedistx = fabs(game->player.px - dda->mapx);
		dda->wall_side = WEST;
		dda->wall_h = game->player.px - (int)game->player.px;
	}
	if (game->player.rad = 1.5 * PI)
	{
		while (game->map[dda->mapy][dda->mapx] != '1')
		{
			dda->mapx--;
		}
		dda->sidedistx = fabs(game->player.px - dda->mapx);
		dda->wall_side = EAST;
		dda->wall_h = game->player.px - (int)game->player.px;
	}
}

void	calc_distance(t_render *game, t_raycasting *cast, t_dda dda)
{
	double	perpwalldist;
	double	corrected_distance;

	if (dda.wall_side == NORTH || dda.wall_side == SOUTH)
		perpwalldist = dda.sidedisty - dda.stepy;
	else
		perpwalldist = dda.sidedistx - dda.stepx;
	corrected_distance = perpwalldist * cos(dda.radian - game->player.rad);
	cast->distance[dda.cast_n] = corrected_distance;
}
