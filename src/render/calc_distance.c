/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/01/31 15:31:39 by julius        ########   odam.nl         */
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
	double	radian_increase;

	
	radian_increase = FOV / WIDTH;
	// dda.player_dirx = cos(game->player.rad);
	// dda.player_diry = sin(game->player.rad);

	dda.radian = game->player.rad - (FOV / 2);
	if (dda.radian < 0)
		dda.radian += 2 * PI;
	
	dda.cast_n = 0;
	while (dda.cast_n < WIDTH )// WIDTH * 
	{
		//dda.camera_x = 2 * dda.cast_n / (double)WIDTH - 1;
		//dda.ray_dirx = dda.player_dirx + dda.plane_x * dda.camera_x;
        //dda.ray_diry = dda.player_diry + dda.plane_y * dda.camera_x;
		//dda.mapx = (int)game->player.px;
		//dda.mapy = (int)game->player.py;
		calc_dda(game, &dda);
		//set_dist_wallh(game, &dda);
		// if (dda.cast_n > 120 && dda.cast_n < 134)
		// {
		printf("ray[%zu] dist= %f, wall = %i\n", dda.cast_n, game->cast.distance[dda.cast_n], game->cast.wall_side[dda.cast_n]);
		printf("\n");
		// }
		dda.radian += radian_increase;
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
		printf("ray[%zu] stepx: %f, stepy %f\n", dda->cast_n, dda->stepx, dda->stepy);
		printf("ray[%zu] mapx: %d, mapy %d\n", dda->cast_n, dda->mapx, dda->mapy);
	// }


// 	while (1)
// 	{
// 		if (dda->start_distx < dda->start_disty)
// 		{
// 			dda->start_distx += dda->deltaX;
// 			dda->mapx += dda->stepx;
// 		}
// 		else
// 		{
// 			dda->start_disty += dda->deltaY;
// 			dda->mapy += dda->stepy;
// 		}
// 		// if (dda->cast_n > 120 && dda->cast_n < 134)
// 			printf("mapx: %d, mapy: %d\n", dda->mapx, dda->mapy);
// 		if (game->map[dda->mapy][dda->mapx] == '1')
// 		{
// 			set_values(dda);
// 			break ;
// 		}
// 	}
// }
}

float get_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));
}

void	calc_step_sidedist(t_render *game, t_dda *dda)
{
	// horizontal dda
	double final_dist;
	double disH = 100000000;
	double hx = game->player.px;
	double hy = game->player.py;
	double dof = 0;
	float aTan = -1/tan(dda->radian);
	if (dda->radian > PI)
	{
		dda->ray_diry = (int)game->player.py - 0.0001;
		dda->ray_dirx = (game->player.py - dda->ray_diry) * aTan + game->player.px;
		dda->stepy = -1;
		dda->stepx = -dda->stepy * aTan;
	}
	if (dda->radian < PI)
	{
		dda->ray_diry = (int)game->player.py + 1;
		dda->ray_dirx = (game->player.py - dda->ray_diry) * aTan + game->player.px;
		dda->stepy = 1;
		dda->stepx = -dda->stepy * aTan;
	}
	if (dda->radian == 0 || dda->radian == PI)
	{
		dda->ray_dirx = game->player.px;
		dda->ray_diry = game->player.py;
	}
	while (1)
	{
		dda->mapx = (int)(dda->ray_dirx);
		dda->mapy = (int)(dda->ray_diry);
		if (dda->mapx > 4 || dda->mapy > 7 || dda->mapx < 0 || dda->mapy < 0)
			break ; 
		if (game->map[dda->mapy][dda->mapx] == '1')
		{
			hx = dda->ray_dirx;
			hy = dda->ray_diry;
			disH = get_dist(game->player.px, game->player.py, hx, hy);
			break;
		}
		else
		{
			dda->ray_dirx += dda->stepx;
			dda->ray_diry += dda->stepy;
			dof += 1;
		}
	}
	


	// vertical


	float disV = 100000000;
	float vx = game->player.px;
	float vy = game->player.py;
	dof = 0;
	float nTan = -tan(dda->radian);
	if (dda->radian > PI2 && dda->radian < PI3)
	{
		dda->ray_dirx = (int)game->player.px - 0.0001;
		dda->ray_diry = (game->player.px - dda->ray_dirx) * nTan + game->player.py;
		dda->stepx = -1;
		dda->stepy = -dda->stepx * nTan;
	}
	if (dda->radian < PI2 || dda->radian > PI3)
	{
		dda->ray_dirx = (int)game->player.px + 1;
		dda->ray_diry = (game->player.px - dda->ray_dirx) * nTan + game->player.py;
		dda->stepx = 1;
		dda->stepy = -dda->stepx * nTan;
	}
	if (dda->radian == 0 || dda->radian == PI)
	{
		dda->ray_dirx = game->player.px;
		dda->ray_diry = game->player.py;
	}
	while (1)
	{
		dda->mapx = (int)(dda->ray_dirx);
		dda->mapy = (int)(dda->ray_diry);
		if (dda->mapx > 4 || dda->mapy > 7 || dda->mapx < 0 || dda->mapy < 0)
			break ; 
		if (game->map[dda->mapy][dda->mapx] == '1')
		{
			vx = dda->ray_dirx;
			vy = dda->ray_diry;
			disV = get_dist(game->player.px, game->player.py, vx, vy);
			break;
		}
		else
		{
			dda->ray_dirx += dda->stepx;
			dda->ray_diry += dda->stepy;
			dof += 1;
		}
	}
	if (disV < disH)
	{
		dda->ray_dirx = vx;
		dda->ray_diry = vy;
		final_dist = disV;
		if (dda->radian > PI2 && dda->radian < PI3)
			game->cast.wall_side[dda->cast_n] = EAST;
		else
			game->cast.wall_side[dda->cast_n] = WEST;
		game->cast.wall_h[dda->cast_n] = dda->ray_diry - (int)dda->ray_diry;
		// set north or south
	}
	else
	{
		dda->ray_dirx = hx;
		dda->ray_diry = hy;
		final_dist = disH;
		if (dda->radian > PI && dda->radian < PI2)
			game->cast.wall_side[dda->cast_n] = NORTH;
		else
			game->cast.wall_side[dda->cast_n] = SOUTH;
		game->cast.wall_h[dda->cast_n] = dda->ray_dirx - (int)dda->ray_dirx;
		// set north or south
	}
	//game->cast.distance[dda->cast_n] = correct_distance()
	double cast_angle = game->player.rad - dda->radian;
	if (cast_angle < 0)
		cast_angle += 2 * PI;
	if (cast_angle > 2 * PI)
		cast_angle -= 2 * PI;
	game->cast.distance[dda->cast_n] = final_dist * cos(cast_angle);
	game->cast.wall_h[dda->cast_n] = dda->ray_dirx - (int)dda->ray_dirx;
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
