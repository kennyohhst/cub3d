/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/11 17:14:45 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calc_dda(t_render *game, t_dda *dda);
void	calc_step_sidedist(t_render *game, t_dda *dda);
void	set_values(t_dda *dda);
void	straight_lines(t_render *game, t_dda *dda);
void	set_distance(t_render *game, t_dda dda);

/**
 * @brief calculates for each ray:
 * 1. the distance player-wall
 * 2. the wall_h where the wall is hit
 * 3. the wall_side, indicating the texture to be used
*/
void	calc_distance(t_render *game)
{
	t_dda	dda;

	dda.radian = game->player.rad - (FOV / 2);
	dda.cast_n = 0;
	dda.mapx = (int)game->player.px;
	dda.mapy = (int)game->player.py;
	while (dda.cast_n < WIDTH)
	{
		calc_dda(game, &dda);
		game->cast.wall_h[dda.cast_n] = dda.wall_h;
		game->cast.wall_side[dda.cast_n] = dda.wall_side;
		set_distance(game, dda);
		dda.radian += game->cast.ray_steps;
		dda.cast_n++;
	}
}

/**
 * @brief sets wallx, wally, wall_hit and wall_side
 */
void	calc_dda(t_render *game, t_dda *dda)
{
	if (dda->radian == 0 || dda->radian == 0.5 * PI || dda->radian == PI
		|| dda->radian == 1.5 * PI)
		straight_lines(game, dda);
	// calculate step and initial sideDist
	calc_step_sidedist(game, dda);
	// actual DDA
	while (1)
	{
		// jump to next map square in x or y direction
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
		// check if ray has hit a wall
		if (game->map[dda->mapy][dda->mapx] > 0)
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
}

void	calc_step_sidedist(t_render *game, t_dda *dda)
{
	dda->deltaX = fabs(1 / cos(dda->radian));
	dda->deltaY = fabs(1 / sin(dda->radian));
	if (cos(dda->radian) < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (game->player.px - dda->mapx) * dda->deltaX;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1.0 - game->player.px) * dda->deltaX;
	}
	if (sin(dda->radian) < 0)
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

void handle_north_south(t_render *game, t_dda *dda)
{
    if (dda->radian == 0)
    {
        while (game->map[dda->mapy][dda->mapx] != '1')
            dda->mapy--;
        dda->wall_side = SOUTH;
    }
    else if (game->player.rad == PI)
    {
        while (game->map[dda->mapy][dda->mapx] != '1')
            dda->mapy++;
        dda->wall_side = NORTH;
    }
    dda->sidedisty = abs(game->player.py - dda->mapy);
    dda->wall_h = game->player.py - (int)game->player.py;
}

void handle_east_west(t_render *game, t_dda *dda)
{
    if (game->player.rad == 0.5 * PI)
    {
        while (game->map[dda->mapy][dda->mapx] != '1')
            dda->mapx++;
        dda->wall_side = WEST;
    }
    else if (game->player.rad == 1.5 * PI)
    {
        while (game->map[dda->mapy][dda->mapx] != '1')
            dda->mapx--;
        dda->wall_side = EAST;
    }
    dda->sidedistx = abs(game->player.px - dda->mapx);
    dda->wall_h = game->player.px - (int)game->player.px;
}

void straight_lines(t_render *game, t_dda *dda)
{
    if (dda->radian == 0 || dda->radian == PI)
    {
        handle_north_south(game, dda);
    }
    else
    {
        handle_east_west(game, dda);
    }
}

void	set_distance(t_render *game, t_dda dda)
{
	double	perpwalldist;
	double	corrected_distance;

	if (dda.wall_side == NORTH || dda.wall_side == SOUTH)
		perpwalldist = dda.sidedisty - dda.stepy;
	else
		perpwalldist = dda.sidedistx - dda.stepx;
	corrected_distance = perpwalldist * cos(dda.radian - game->player.rad);
	game->cast.distance[dda.cast_n] = corrected_distance;
}
