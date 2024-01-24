/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/24 08:47:03 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calc_dda(t_render *game, t_dda *dda);
void	calc_step_sidedist(t_render *game, t_dda *dda);
void	set_values(t_dda *dda);
void	handle_east_west(t_render *game, t_dda *dda);
void	set_dist_wallh(t_render *game, t_dda *dda);
void	handle_north_south(t_render *game, t_dda *dda);

/**
 * @brief calculates for each ray:
 * 1. the distance player-wall
 * 2. the wall_h where the wall is hit
 * 3. the wall_side, indicating the texture to be used
*/
void	calc_distance(t_render *game)
{
	t_dda	dda;
	double	ray_steps;
	
	ray_steps = FOV / WIDTH;
	dda.dirx = cos(game->player.rad);
	dda.diry = sin(game->player.rad);
	dda.plane_x = dda.diry;
	dda.plane_y = -dda.dirx;



	dda.radian = game->player.rad - (FOV / 2);
	if (dda.radian < 0)
		dda.radian += 2 * PI;
	



	dda.cast_n = 0;
	while (dda.cast_n < WIDTH) // WIDTH * 
	{
		dda.camera_x = 2 * dda.cast_n / (double)WIDTH - 1;
		dda.wall_h = -1;
		dda.mapx = (int)game->player.px;
		dda.mapy = (int)game->player.py;
		calc_dda(game, &dda);
		set_dist_wallh(game, &dda);
		game->cast.wall_h[dda.cast_n] = dda.wall_h;
		game->cast.wall_side[dda.cast_n] = dda.wall_side;
		if (dda.cast_n > 1200 && dda.cast_n < 1340)
		{
		printf("ray[%zu] dist= %f, wall = %i\n", dda.cast_n, game->cast.distance[dda.cast_n], dda.wall_side);
		printf("ray[%zu] rad: %f, stepx: %d, stepy: %d\n", dda.cast_n, dda .radian, dda.stepx, dda.stepy);
		printf("ray[%zu] sidedistY: %f, deltaY %f\n", dda.cast_n, dda.sidedisty, dda.deltaY);
		printf("ray[%zu] sidedistX: %f, deltaX %f\n", dda.cast_n, dda.sidedistx, dda.deltaX);
		printf("\n");
		}
		dda.radian += ray_steps;
		dda.cast_n++;
	}
}

/**
 * @brief sets wallx, wally, wall_hit and wall_side
 */
void	calc_dda(t_render *game, t_dda *dda)
{
	calc_step_sidedist(game, dda);
	while (1)
	{
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += dda->deltaX;
			dda->mapx += dda->stepx;
		}
		else
		{
			dda->sidedisty += dda->deltaY;
			dda->mapy += dda->stepy;
		}
		if (dda->cast_n > 1200 && dda->cast_n < 1340)
			printf("mapx: %d, mapy: %d\n", dda->mapx, dda->mapy);
		if (game->map[(int)(dda->mapy)][(int)(dda->mapx)] > '0')
		{
			set_values(dda);
			break ;
		}
	}
}

void	set_values(t_dda *dda)
{
	if (dda->sidedistx < dda->sidedisty)
	{
		if (dda->stepy == -1)
			dda->wall_side = NORTH;
		else
			dda->wall_side = SOUTH;
	}
	else
	{
		if (dda->stepx == -1)
			dda->wall_side = EAST;
		else
			dda->wall_side = WEST;
	}
}

void	calc_step_sidedist(t_render *game, t_dda *dda)
{
	double raydirx = dda->dirx + dda->plane_x * dda->camera_x;
	double raydiry = dda->diry + dda->plane_y * dda->camera_x;
	dda->deltaX = sqrt(1 + (raydiry* raydiry) / (raydirx * raydirx));
	dda->deltaY = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
	if (raydirx < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (game->player.px - dda->mapx) * dda->deltaX;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1.0 - game->player.px) * dda->deltaX;
	}
	if (raydiry < 0)
	{
		dda->stepy = -1;
		dda->sidedisty = (game->player.py - dda->mapy) * dda->deltaY;
	}
	else
	{
		dda->stepy = 1;
		dda->sidedisty = (dda->mapy + 1.0 - game->player.py) * dda->deltaY;
	}
}

/**
 * @brief calculates the distance from the player to the wall && sets wall_h
 * if wall_h has not yet been set
 * 
*/
void	set_dist_wallh(t_render *game, t_dda *dda)
{
	double	perpendicular_dist;
	// double	corrected_dist;
	double	wall_hit;

	if (dda->wall_side == NORTH || dda->wall_side == SOUTH)
		perpendicular_dist = dda->sidedisty - dda->deltaY;
	else
		perpendicular_dist = dda->sidedistx - dda->deltaX;
	// corrected_dist = perpendicular_dist * cos(dda->radian - game->player.rad);
	game->cast.distance[dda->cast_n] = fabs(perpendicular_dist);
	if (dda->wall_h == -1)
	{
		if (dda->wall_side == NORTH || dda->wall_side == SOUTH)
			wall_hit = game->player.px + perpendicular_dist * sin(dda->radian); // change to  cirrected dist
		else
			wall_hit = game->player.py - perpendicular_dist * cos(dda->radian); // change to corrected dist
		dda->wall_h = wall_hit - (int)wall_hit;
	}
}
