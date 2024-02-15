/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: julius <julius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 12:19:43 by julius        #+#    #+#                 */
/*   Updated: 2024/02/15 12:52:30 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief creates a 32 bit integer from RGB values
 * @param a alpha
 * @param r red
 * @param g green
 * @param b blue
*/
uint32_t	get_RGB(int a, int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_game(t_render *game)
{
	mlx_delete_image(game->mlx, game->text.img_backgrnd);
	mlx_delete_texture(game->text.t_wall_n);
	mlx_delete_texture(game->text.t_wall_s);
	mlx_delete_texture(game->text.t_wall_e);
	mlx_delete_texture(game->text.t_wall_w);
	mlx_terminate(game->mlx);
	free(game->cast.distance);
	free(game->cast.wall_side);
	free(game->cast.wall_h);
	free(game);
}
