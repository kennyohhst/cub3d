/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:02:50 by code              #+#    #+#             */
/*   Updated: 2024/01/04 20:05:20 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	flood_it(int x, int y, t_map **flood, char **full_map)
{
	run_only_map(full_map);
	if (full_map[x][y] && (full_map[x][y] == '1' || full_map[x][y] == '2'))
		return ;
	// if (full_map[x][y] == 'C')
	// 	(*flood)->collectables--;
	// if (full_map[x][y] == 'E')
	// 	(*flood)->exit--;
	full_map[x][y] = '2';
	flood_it(x, y + 1, flood, full_map);
	flood_it(x, y - 1, flood, full_map);
	flood_it(x + 1, y, flood, full_map);
	flood_it(x - 1, y, flood, full_map);
}

void	collectables(t_map **flood, char **full_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(*flood)->collectables = 0;
	while (full_map[x])
	{
		if (full_map[x][y] == 'C')
			(*flood)->collectables++;
		if (full_map[x][y] == '\0')
		{
			y = 0;
			x++;
		}
		else
			y++;
	}
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

int	prep_flood(char **full_map)
{
	t_map	*flood;
	// int		collect;

	flood = malloc(sizeof(t_map));
	player(&flood, full_map);
	// collectables(&flood, full_map);
	// flood->exit = 1;
	// collect = flood->collectables;
	flood_it(flood->player_x, flood->player_y, &flood, full_map);
	if (flood->collectables != 0 || flood->exit != 0)
		exit(write(2, "Error\nprep_flood\n", 17));
	free(flood);
	return (0);
}
