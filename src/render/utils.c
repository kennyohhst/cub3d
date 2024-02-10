/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: julius <julius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 12:19:43 by julius        #+#    #+#                 */
/*   Updated: 2024/02/10 17:59:02 by jde-baai      ########   odam.nl         */
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
	return ((a << 24) | (b << 16) | (g << 8) | r);
}

size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
