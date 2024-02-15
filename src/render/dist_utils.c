/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dist_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 10:55:24 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/15 13:01:11 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	set_hor_start_values(t_render *game, t_calc *calc)
{
	float	atan;

	atan = -1 / tan(calc->radian);
	if (calc->radian > PI)
	{
		calc->hor_ray_y = (int)game->player.py - 0.0001;
		calc->hor_ray_x = (game->player.py - calc->hor_ray_y) * atan
			+ game->player.px;
		calc->hor_stepy = -1;
		calc->hor_stepx = -calc->hor_stepy * atan;
	}
	if (calc->radian < PI)
	{
		calc->hor_ray_y = (int)game->player.py + 1;
		calc->hor_ray_x = (game->player.py - calc->hor_ray_y) * atan
			+ game->player.px;
		calc->hor_stepy = 1;
		calc->hor_stepx = -calc->hor_stepy * atan;
	}
}

void	set_vert_start_values(t_render *game, t_calc *calc)
{
	float	ntan;

	ntan = -tan(calc->radian);
	if (calc->radian > PI2 && calc->radian < PI3)
	{
		calc->ver_ray_x = (int)game->player.px - 0.0001;
		calc->ver_ray_y = (game->player.px - calc->ver_ray_x) * ntan
			+ game->player.py;
		calc->ver_stepx = -1;
		calc->ver_stepy = -calc->ver_stepx * ntan;
	}
	if (calc->radian < PI2 || calc->radian > PI3)
	{
		calc->ver_ray_x = (int)game->player.px + 1;
		calc->ver_ray_y = (game->player.px - calc->ver_ray_x) * ntan
			+ game->player.py;
		calc->ver_stepx = 1;
		calc->ver_stepy = -calc->ver_stepx * ntan;
	}
}
