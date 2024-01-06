/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:02:50 by code              #+#    #+#             */
/*   Updated: 2024/01/06 19:11:06 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	flood_it(int x, int y, t_map **flood, char **full_map)
{
	printf("LET OP!	%d\n", (*flood)->collectables++);
	if (y < 0)
	{
		y++;
		(*flood)->exit = 1;
	}
	run_only_map(full_map);
	if (x >= dp_strlen(full_map))
		x = dp_strlen(full_map) - 1;
	if (x < 0)
		x++;
	printf("x = %d, y = %d\n", x, y);
	if (y >= (int) ft_strlen(full_map[x]))
		y = (int) ft_strlen(full_map[x]) -1;
	if (full_map[x][y] && (full_map[x][y] == '1' || full_map[x][y] == '2'))
		return ;
	full_map[x][y] = '2';
	if (!full_map[x][y + 1])
		(*flood)->exit = 1;
	flood_it(x, y + 1, flood, full_map);
	flood_it(x, y - 1, flood, full_map);
	flood_it(x + 1, y, flood, full_map);
	flood_it(x - 1, y, flood, full_map);
	
}

void	player(t_map **flood, char **full_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (full_map)
	{
		if (full_map[x][y] == 'N' || full_map[x][y] == 'O'
			|| full_map[x][y] == 'S' || full_map[x][y] == 'W')
		{
			(*flood)->player_x = x;
			(*flood)->player_y = y;
			break ;
		}
		if (full_map[x][y] == '\0')
		{
			y = 0;
			x++;
		}
		else
			y++;
	}
}

bool	prep_flood(char **full_map)
{
	t_map	*flood;

	flood = malloc(sizeof(t_map));
	flood->exit = 0;
	player(&flood, full_map);
	flood->collectables = 0;
	flood_it(flood->player_x, flood->player_y, &flood, full_map);
	if (flood->exit)
		return (free(flood), true);
	free(flood);
	return (false);
}
