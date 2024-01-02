/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/02 17:54:52 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct s_raycasting
{
	int		rayx;
	int		rayy;
	int		stepx;
	int		stepy;
	double	ray_steps;
	double	*distance; // distance from player to wall per ray (euclidean)
	double	*height; // height of wall per ray
	int		*wall_side; // 1 = north, 2 = east, 3 = south, 4 = west per ray
	int32_t *pixels_buffer; // pixels to be placed in img_walls
}				t_raycasting;

typedef struct s_local_dda
{
	size_t cast_n;
	double radian;
	int wallx;
	int wally;
	int wall_hit;
	int wall_side;
	double stepx;
	double stepy;
	double sidedistx;
	double sidedisty;
}			t_dda;

// to do image rezier in place pixels, based on the height of the pixel and the height of the textured image (64x64)

void calc_dda(t_render *game, t_raycasting *cast, t_dda *dda);
bool	calculations(t_render *game, t_raycasting *dda);

bool dda_main(t_render *game)
{
	t_raycasting	*cast;
	int		i;


	cast = ft_calloc(sizeof(t_raycasting), 1);
	cast->distance = malloc(sizeof(double) * WIDTH);
	cast->wall_side = malloc(sizeof(int) * WIDTH);
	cast->ray_steps = FOV / WIDTH;

	size_t total_pixels = game->text.img_walls->width
		* game->text.img_walls->height;

	calculations(game, cast); // calculates distances, intersections and wall_side
	clear_pixels(game); // gives all pixels in img_walls empty color
	calc_pixels(game, cast); // places pixels calculated into pixels_buffer
	place_pixels(game, cast); // places pixels_buffer into img_walls
	cast->rayx = (int)game->player.px;
	cast->rayy = (int)game->player.py;


}

void	calc_distance_height(t_render *game, t_raycasting *cast, t_dda dda)
{

}

bool calculations(t_render *game, t_raycasting *cast)
{
	t_dda	dda;

	dda.radian = game->player.rad - (FOV / 2);

	dda.cast_n = 0;
	while (dda.cast_n < WIDTH)
	{
		calc_dda(game, cast, &dda); // calculates intersection with first wall
		calc_distance_height(game, cast, dda); // calculates distance from player to wall
		dda.radian += cast->ray_steps;
		dda.cast_n++;
	}
}


void straight_lines(void);

/**
 * @brief sets wallx, wally, wall_hit and wall_side
*/
void calc_dda(t_render *game, t_raycasting *cast, t_dda *dda)
{
    int mapX = (int)game->player.px;
    int mapY = (int)game->player.py;

    double deltaX = fabs(1 / cos(dda->radian));
    double deltaY = fabs(1 / sin(dda->radian));

    // calculate step and initial sideDist
    if (cos(dda->radian) < 0)
    {
        dda->stepx = -1;
        dda->sidedistx = (game->player.px - mapX) * deltaX;
    }
    else
    {
        dda->stepx = 1;
        dda->sidedistx = (mapX + 1.0 - game->player.px) * deltaX;
    }
    if (sin(dda->radian) < 0)
    {
        dda->stepy = -1;
        dda->sidedisty = (game->player.py - mapY) * deltaY;
    }
    else
    {
        dda->stepy = 1;
        dda->sidedisty = (mapY + 1.0 - game->player.py) * deltaY;
    }
	
	// actual DDA
	while (dda->wall_hit == 0)
	{
		// jump to next map square in x or y direction
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += deltaX;
			mapX += dda->stepx;
		}
		else
		{
			dda->sidedisty += deltaY;
			mapY += dda->stepy;
		}

		// check if ray has hit a wall
		if (game->map[mapY][mapX] > 0)
		{
			dda->wall_hit = 1;
			if (dda->sidedistx < dda->sidedisty)
			{
				if (dda->stepx < 0)
				{
					dda->wall_side = WEST;
				}
				else
				{
					dda->wall_side = EAST;
				}
			}
			else
			{
				if (dda->stepy < 0)
				{
					dda->wall_side = NORTH;
				}
				else
				{
					dda->wall_side = SOUTH;
				}
			}
		}
	}
}

void straight_lines(void)
{

	// if (game->player.rad = 0)
	// {
	// 	while (game->map[dda.sidedisty][dda.sidedistx] != '1')
	// 	{
	// 		dda.sidedisty--;
	// 	}
	// 	dda.wallx = dda.sidedistx;
	// 	dda.wally = game->player.py;
	// 	//decrement y
	// }
	// if (game->player.rad = 1*PI)
	// {
	// 	while (game->map[dda.sidedisty][dda.sidedistx] != '1')
	// 	{
	// 		dda.sidedisty++;
	// 	}
	// 	dda->distances[cast_n] = game->player.py - rayy;
	// 	//increment y
	// }
	// if (game->player.rad = 0.5*PI)
	// {
	// 	while (game->map[dda.sidedisty][dda.sidedistx] != '1')
	// 	{
	// 		dda.sidedistx++;
	// 	}
	// 	dda->distances[cast_n] = rayx - game->player.px;
	// 	//increment x
	// }
	// if (game->player.rad = 1.5*PI)
	// {
	// 	while (game->map[dda.sidedisty][dda.sidedistx] != '1')
	// 	{
	// 		dda.sidedistx--;
	// 	}
	// 	dda->distances[cast_n] = game->player.px - rayx;
	// 	//decrement x
	// }
}