/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:03:33 by code              #+#    #+#             */
/*   Updated: 2024/01/11 13:19:52 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	make_two(char c)
{
	return (c == '0' || c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

// MAKE ME SMALLER!!!!!!
	// if (x == dp_strlen(full_map)-1 || x == 0 || 
	// (ft_strlen(full_map[x-1]) < ft_strlen(full_map[x]) 
	// && y >= (int) ft_strlen(full_map[x-1])) ||
	// (ft_strlen(full_map[x+1]) < ft_strlen(full_map[x]) 
	// && y >= (int) ft_strlen(full_map[x+1])))
	// 	return (1);
	// if (full_map[x][y + 1] == '\0')
	// 	return (1);
	// if (y != 0 && (full_map[x][y+1] == ' ' || full_map[x][y-1] == ' ' ||
	// full_map[x+1][y] == ' ' || full_map[x-1][y] == ' '))
	// 	return (1);