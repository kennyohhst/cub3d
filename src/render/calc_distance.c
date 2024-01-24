/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/24 20:51:00 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	else if (dir == 'N')
	{
		data->player->dirx = -1;
		data->player->diry = 0;
	}


		player_dir = player_pos(data);
	player_direction(data, player_dir);
	planeRatio = 0.66; // specified length ratio
	// Calculate the length of the direction vector
	dirLength = sqrt(data->player->dirx * data->player->dirx \
	+ data->player->diry * data->player->diry);
	// Calculate the new planeX and planeY based on the ratio
	data->player->planex = data->player->diry / dirLength * planeRatio;
	data->player->planey = -data->player->dirx / dirLength * planeRatio;


*/



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
	double	plane_ratio;
	double dirLength;
	
	ray_steps = FOV / WIDTH;
	dda.player_dirx = 0;
	dda.player_diry = -1;
	plane_ratio = 0.66;
	dirLength = sqrt(dda.player_dirx * dda.player_dirx + dda.player_diry * dda.player_diry);
	dda.plane_x = dda.player_dirx / dirLength * plane_ratio;
	dda.plane_y = dda.player_diry / dirLength * plane_ratio;
	dda.deltaX = 0.0;
	dda.deltaY = 0.0;


	dda.radian = game->player.rad - (FOV / 2);
	if (dda.radian < 0)
		dda.radian += 2 * PI;
	
	dda.cast_n = 0;
	while (dda.cast_n < WIDTH) // WIDTH * 
	{
		dda.camera_x = 2 * dda.cast_n / (double)WIDTH - 1;
		dda.ray_dirx = dda.player_dirx + dda.plane_x * dda.camera_x;
        dda.ray_diry = dda.player_diry + dda.plane_y * dda.camera_x;
		dda.mapx = (int)game->player.px;
		dda.mapy = (int)game->player.py;
		calc_dda(game, &dda);
		set_dist_wallh(game, &dda);
		game->cast.wall_h[dda.cast_n] = dda.wall_h;
		game->cast.wall_side[dda.cast_n] = dda.wall_side;
		// if (dda.cast_n > 120 && dda.cast_n < 134)
		// {
		printf("ray[%zu] dist= %f, wall = %i\n", dda.cast_n, game->cast.distance[dda.cast_n], dda.wall_side);
		printf("\n");
		// }
		// dda.radian += ray_steps;
		dda.cast_n++;
	}
}

/**
 * @brief sets wallx, wally, wall_hit and wall_side
 */
void	calc_dda(t_render *game, t_dda *dda)
{
	calc_step_sidedist(game, dda);

	// if (dda->cast_n > 120 && dda->cast_n < 134)
	// {
		printf("ray[%zu] dirX: %f, dirY %f\n", dda->cast_n, dda->ray_dirx, dda->ray_diry);
		printf("ray[%zu] stepx: %d, stepy %d\n", dda->cast_n, dda->stepx, dda->stepy);
		printf("ray[%zu] start_x: %f, deltax %f\n", dda->cast_n, dda->start_distx, dda->deltaX);
		printf("ray[%zu] start_y: %f, deltay %f\n", dda->cast_n, dda->start_disty, dda->deltaY);
	// }


	while (1)
	{
		if (dda->start_distx < dda->start_disty)
		{
			dda->start_distx += dda->deltaX;
			dda->mapx += dda->stepx;
		}
		else
		{
			dda->start_disty += dda->deltaY;
			dda->mapy += dda->stepy;
		}
		// if (dda->cast_n > 120 && dda->cast_n < 134)
			printf("mapx: %d, mapy: %d\n", dda->mapx, dda->mapy);
		if (game->map[dda->mapy][dda->mapx] == '1')
		{
			set_values(dda);
			break ;
		}
	}
}

/**
 * @todo figure out what would be a good way to calc this cause idfk
 *     dda->deltaX = sqrt(1 + (dda->ray_diry * dda->ray_diry) / (dda->ray_dirx * dda->ray_dirx));
    dda->deltaY = sqrt(1 + (dda->ray_dirx * dda->ray_dirx) / (dda->ray_diry * dda->ray_diry));

    if (dda->ray_dirx < 0)
    {
        dda->stepx = -1;
        dda->start_distx = (game->player.px - dda->mapx) * dda->deltaX;
    }
    else
    {
        dda->stepx = 1;
        dda->start_distx = (dda->mapx + 1.0 - game->player.px) * dda->deltaX;
    }
    if (dda->ray_diry < 0)
    {
        dda->stepy = -1;
        dda->start_disty = (game->player.py - dda->mapy) * dda->deltaY;
    }
    else
    {
        dda->stepy = 1;
        dda->start_disty = (dda->mapy + 1.0 - game->player.py) * dda->deltaY;
    }
 * 
*/
void	calc_step_sidedist(t_render *game, t_dda *dda)
{
	if (dda->ray_dirx == 0)
		dda->deltaX = 1e30;
	else
		dda->deltaX = fabs(1 / dda->ray_dirx);
	if (dda->ray_diry == 0)
		dda->deltaY = 1e30;
	else
		dda->deltaY = fabs(1 / dda->ray_diry);
	// ..
	if (dda->ray_dirx < 0)
	{
		dda->stepx = -1;
		dda->start_distx = (game->player.px - dda->mapx) * dda->deltaX;
	}
	else
	{
		dda->stepx = 1;
		dda->start_distx = (dda->mapx + 1.0 - game->player.px) * dda->deltaX;
	}
	if (dda->ray_diry < 0)
	{
		dda->stepy = -1;
		dda->start_disty = (game->player.py - dda->mapy) * dda->deltaY;
	}
	else
	{
		dda->stepy = 1;
		dda->start_disty = (dda->mapy + 1.0 - game->player.py) * dda->deltaY;
	}
}

void	set_values(t_dda *dda)
{
	if (dda->sidedistx < dda->sidedisty)
	{
		if (dda->stepy == -1)
			dda->wall_side = SOUTH;
		else
			dda->wall_side = NORTH;
	}
	else
	{
		if (dda->stepx == -1)
			dda->wall_side = EAST;
		else
			dda->wall_side = WEST;
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
	if (dda->wall_side == NORTH || dda->wall_side == SOUTH)
		wall_hit = game->player.px + perpendicular_dist * sin(dda->radian); // change to  cirrected dist
	else
		wall_hit = game->player.py - perpendicular_dist * cos(dda->radian); // change to corrected dist
	dda->wall_h = wall_hit - (int)wall_hit;
}
