/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/11 15:53:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/15 11:53:33 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	run_calc(t_render *game, t_calc *calc);
double	find_hor_wall(t_render *game, t_calc *calc, int xlimit, int ylimit);
double	find_ver_wall(t_render *game, t_calc *calc, int xlimit, int ylimit);
void	set_dist(t_render *game, t_calc *calc, double disH, double disV);

/**
 * @brief calculates for each ray:
 * 1. the distance player-wall
 * 2. the wall_h where the wall is hit
 * 3. the wall_side, indicating the texture to be used
*/
void	calc_distance(t_render *game)
{
	t_calc	calc;
	double	radian_increase;

	radian_increase = FOV / WIDTH;
	calc.radian = game->player.rad - (FOV / 2);
	if (calc.radian < 0)
		calc.radian += 2 * PI;
	calc.cast_n = 0;
	while (calc.cast_n < WIDTH )
	{
		if (calc.radian == 0)
			calc.radian = 0e30;
		run_calc(game, &calc);
		calc.radian += radian_increase;
		if (calc.radian > 2 * PI)
			calc.radian -= 2 * PI;
		calc.cast_n++;
	}
}

/**
 * @brief finds the horizontal and vertical distance
 * 		sets the distance to the shortests distance
 * 		sets the wall_side the wall hit
 * 
 * @todo remove xlimit from the params;
*/
void	run_calc(t_render *game, t_calc *calc)
{
	double disH;
	double disV;
	double	cast_angle;
	int xlimit;
	int ylimit;

	xlimit = ft_strlen(game->map[0]);
	ylimit = array_len(game->map) - 1;
	set_hor_start_values(game, calc);
	set_vert_start_values(game, calc);
	disH = find_hor_wall(game, calc, xlimit, ylimit);
	disV = find_ver_wall(game, calc, xlimit, ylimit);
	set_dist(game, calc, disH, disV);
	cast_angle = game->player.rad - calc->radian;
	if (cast_angle < 0)
		cast_angle += 2 * PI;
	if (cast_angle > 2 * PI)
		cast_angle -= 2 * PI;
	game->cast.distance[calc->cast_n] = calc->distance * cos(cast_angle);
}

double	find_hor_wall(t_render *game, t_calc *calc, int xlimit, int ylimit)
{
	int		mapx;
	int		mapy;

	while (1)
	{
		mapx = (int)calc->hor_ray_x;
		mapy = (int)calc->hor_ray_y;
		if (mapy > ylimit || mapy < 0)
			break ;	
		xlimit = ft_strlen(game->map[mapy]);
		if (mapx > xlimit || mapx < 0)
			break ;
		if (game->map[mapy][mapx] == '1')
		{
			return (get_dist(game->player.px, game->player.py, calc->hor_ray_x, calc->hor_ray_y));
		}
		calc->hor_ray_x += calc->hor_stepx;
		calc->hor_ray_y += calc->hor_stepy;
	}
	return (INFINITY);
}

double	find_ver_wall(t_render *game, t_calc *calc, int xlimit, int ylimit)
{
	int		mapx;
	int		mapy;

	while (1)
	{
		mapx = (int)floor(calc->ver_ray_x);
		mapy = (int)floor(calc->ver_ray_y);
		if (mapy > ylimit || mapy < 0)
			break ;	
		xlimit = ft_strlen(game->map[mapy]);
		if (mapx > xlimit || mapx < 0)
			break ; 
		if (game->map[mapy][mapx] == '1')
		{
			return (get_dist(game->player.px, game->player.py, calc->ver_ray_x, calc->ver_ray_y));
		}
		calc->ver_ray_x += calc->ver_stepx;
		calc->ver_ray_y += calc->ver_stepy;
	}
	return (INFINITY);
}

void	set_dist(t_render *game, t_calc *calc, double disH, double disV)
{
	if (disV < disH)
	{
		calc->distance = disV;
		if (calc->radian > PI2 && calc->radian < PI3)
			game->cast.wall_side[calc->cast_n] = EAST;
		else
			game->cast.wall_side[calc->cast_n] = WEST;
		game->cast.wall_h[calc->cast_n] = calc->ver_ray_y - (int)calc->ver_ray_y;
	}
	else
	{
		calc->distance = disH;
		if (calc->radian > PI)
			game->cast.wall_side[calc->cast_n] = SOUTH;
		else
			game->cast.wall_side[calc->cast_n] = NORTH;
		game->cast.wall_h[calc->cast_n] = calc->hor_ray_x - (int)calc->hor_ray_x;
	}
}
