/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:56 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/12/30 18:00:09 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	*dda(t_render *game)
{
	int mapX, mapY;
	double sideDistX, sideDistY;
	double deltaDistX, deltaDistY;
	int stepX, stepY;
	int hit = 0;
	int side;

	// Create an array to hold the distances
	double *distances = malloc(sizeof(double) * game->screen.width);
	if (!distances)
	{
		return (NULL); // Return NULL on allocation failure
	}

	int x = 0;
	while (x < game->screen.width)
	{
		// Initialize variables here based on player position, direction,
			and the current ray angle
		// ...

		// Perform DDA
		while (hit == 0)
		{
			// Jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (game->map[mapX][mapY] > 0)
				hit = 1;
		}

		// Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
		if (side == 0)
			distances[x] = (mapX - game->player.px + (1 - stepX) / 2)
				/ game->player.pd;
		else
			distances[x] = (mapY - game->player.py + (1 - stepY) / 2)
				/ game->player.pd;

		hit = 0; // Reset hit for next ray
		x++;
	}

	return (distances);
}