/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/01 15:13:45 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	run_dda(t_render *game, t_dda *dda);
void	set_horizontal_values(t_render *game, t_dda *dda);
void	set_vertical_values(t_render *game, t_dda *dda);;
double	find_hor_wall(t_render *game, t_dda *dda);
double	find_ver_wall(t_render *game, t_dda *dda);
void	set_values(t_render *game, t_dda *dda, double disH, double disV);

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
	dda.radian = game->player.rad - (FOV / 2);
	if (dda.radian < 0)
		dda.radian += 2 * PI;
	dda.cast_n = 0;
	while (dda.cast_n < WIDTH )// WIDTH * 
	{
		run_dda(game, &dda);
		dda.radian += radian_increase;
		dda.cast_n++;
	}
}

void	run_dda(t_render *game, t_dda *dda)
{
	double disH;
	double disV;
	double	cast_angle;

	set_horizontal_values(game, dda);
	set_vertical_values(game, dda);
	disH = find_hor_wall(game, dda);
	disV = find_ver_wall(game, dda);
	set_values(game, dda, disH, disV);
	cast_angle = game->player.rad - dda->radian;
	if (cast_angle < 0)
		cast_angle += 2 * PI;
	if (cast_angle > 2 * PI)
		cast_angle -= 2 * PI;
	game->cast.distance[dda->cast_n] = dda->distance * cos(cast_angle);
}

float get_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));
}

double	find_hor_wall(t_render *game, t_dda *dda)
{
	while (1)
	{
		dda->mapx = (int)(dda->hor_ray_x);
		dda->mapy = (int)(dda->hor_ray_y);
		if (dda->mapx > 4 || dda->mapy > 7 || dda->mapx < 0 || dda->mapy < 0)
			break ; 
		if (game->map[dda->mapy][dda->mapx] == '1')
		{
			return (get_dist(game->player.px, game->player.py, dda->hor_ray_x, dda->hor_ray_y));
		}
		else
		{
			dda->hor_ray_x += dda->hor_stepx;
			dda->hor_ray_y += dda->hor_stepy;
		}
	}
	return (1000000);
}

double	find_ver_wall(t_render *game, t_dda *dda)
{
	while (1)
	{
		dda->mapx = (int)(dda->ver_ray_x);
		dda->mapy = (int)(dda->ver_ray_y);
		if (dda->mapx > 4 || dda->mapy > 7 || dda->mapx < 0 || dda->mapy < 0)
			break ; 
		if (game->map[dda->mapy][dda->mapx] == '1')
		{
			return (get_dist(game->player.px, game->player.py, dda->ver_ray_x, dda->ver_ray_y));
		}
		else
		{
			dda->ver_ray_x += dda->ver_stepx;
			dda->ver_ray_y += dda->ver_stepy;
		}
	}
	return (1000000);
}

void	set_values(t_render *game, t_dda *dda, double disH, double disV)
{
	if (disV < disH)
	{
		dda->distance = disV;
		if (dda->radian > PI2 && dda->radian < PI3)
			game->cast.wall_side[dda->cast_n] = EAST;
		else
			game->cast.wall_side[dda->cast_n] = WEST;
		game->cast.wall_h[dda->cast_n] = dda->ver_ray_y - (int)dda->ver_ray_y;
	}
	else
	{
		dda->distance = disH;
		if (dda->radian > PI && dda->radian < PI * 2)
			game->cast.wall_side[dda->cast_n] = SOUTH;
		else
			game->cast.wall_side[dda->cast_n] = NORTH;
		game->cast.wall_h[dda->cast_n] = dda->hor_ray_x - (int)dda->hor_ray_x;
	}
}


void	set_horizontal_values(t_render *game, t_dda *dda)
{
	float aTan = -1/tan(dda->radian);
	if (dda->radian > PI)
	{
		dda->hor_ray_y = (int)game->player.py - 0.0001;
		dda->hor_ray_x = (game->player.py - dda->hor_ray_y) * aTan + game->player.px;
		dda->hor_stepy = -1;
		dda->hor_stepx = -dda->hor_stepy * aTan;
	}
	if (dda->radian < PI)
	{
		dda->hor_ray_y = (int)game->player.py + 1;
		dda->hor_ray_x = (game->player.py - dda->hor_ray_y) * aTan + game->player.px;
		dda->hor_stepy = 1;
		dda->hor_stepx = -dda->hor_stepy * aTan;
	}
	if (dda->radian == 0 || dda->radian == PI)
	{
		dda->hor_ray_x = game->player.px;
		dda->hor_ray_y = game->player.py;
	}
}

void	set_vertical_values(t_render *game, t_dda *dda)
{
	float nTan = -tan(dda->radian);
	if (dda->radian > PI2 && dda->radian < PI3)
	{
		dda->ver_ray_x = (int)game->player.px - 0.0001;
		dda->ver_ray_y = (game->player.px - dda->ver_ray_x) * nTan + game->player.py;
		dda->ver_stepx = -1;
		dda->ver_stepy = -dda->ver_stepx * nTan;
	}
	if (dda->radian < PI2 || dda->radian > PI3)
	{
		dda->ver_ray_x = (int)game->player.px + 1;
		dda->ver_ray_y = (game->player.px - dda->ver_ray_x) * nTan + game->player.py;
		dda->ver_stepx = 1;
		dda->ver_stepy = -dda->ver_stepx * nTan;
	}
	if (dda->radian == 0 || dda->radian == PI)
	{
		dda->ver_ray_x = game->player.px;
		dda->ver_stepy = game->player.py;
	}
}
