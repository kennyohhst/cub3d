/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:02:50 by code              #+#    #+#             */
/*   Updated: 2024/02/16 14:59:27 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	sus_player(char **full_map)
{
	size_t	x;
	size_t	y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (full_map && full_map[x])
	{
		while (full_map[x][y])
		{
			if (full_map[x][y] && (full_map[x][y] == 'N'
					|| full_map[x][y] == 'O' || full_map[x][y] == 'S'
					|| full_map[x][y] == 'W'))
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	four_seasons(char **full_map, int x, int y)
{
	if (y < 0)
		y++;
	if (x >= dp_strlen(full_map))
		x = dp_strlen(full_map) - 1;
	if (x < 0)
		x = 0;
	if (y > (int)ft_strlen(full_map[x]))
		y = (int)ft_strlen(full_map[x]) - 1;
	if (full_map[x][y] == '2')
	{
		if (x == dp_strlen(full_map) - 1 || x == 0
			|| (ft_strlen(full_map[x - 1]) < ft_strlen(full_map[x])
				&& y >= (int)ft_strlen(full_map[x - 1]))
			|| (ft_strlen(full_map[x + 1]) < ft_strlen(full_map[x])
				&& y >= (int)ft_strlen(full_map[x + 1])))
			return (1);
		if (full_map[x][y + 1] == '\0')
			return (1);
		if (y != 0 && (full_map[x][y + 1] == ' ' || full_map[x][y - 1] == ' '
				|| full_map[x + 1][y] == ' ' || full_map[x - 1][y] == ' '))
			return (1);
	}
	return (0);
}

void	flood_it(int x, int y, t_map **flood, char **full_map)
{
	if (y < 0)
	{
		y = 0;
		(*flood)->exit = 1;
	}
	if (x >= dp_strlen(full_map))
		x = dp_strlen(full_map) - 1;
	if (x < 0)
		x++;
	if (y >= (int)ft_strlen(full_map[x]))
		y = (int)ft_strlen(full_map[x]) - 1;
	if (full_map[x][y] && (full_map[x][y] == '1' || full_map[x][y] == '2'
			|| full_map[x][y] == ' '))
		return ;
	full_map[x][y] = '2';
	if (four_seasons(full_map, x, y))
		(*flood)->exit = 1;
	flood_it(x, y + 1, flood, full_map);
	flood_it(x, y - 1, flood, full_map);
	flood_it(x + 1, y, flood, full_map);
	flood_it(x - 1, y, flood, full_map);
	flood_it(x - 1, y - 1, flood, full_map);
	flood_it(x - 1, y + 1, flood, full_map);
	flood_it(x + 1, y - 1, flood, full_map);
	flood_it(x + 1, y + 1, flood, full_map);
}

bool	player(t_map **flood, char **full_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (full_map && full_map[x])
	{
		if (full_map[x][y] && (full_map[x][y] == 'N' || full_map[x][y] == 'O'
				|| full_map[x][y] == 'S' || full_map[x][y] == 'W'))
		{
			(*flood)->player_x = x;
			(*flood)->player_y = y;
			return (false);
		}
		if (full_map[x][y] == '\0')
		{
			y = 0;
			x++;
		}
		else
			y++;
	}
	return (true);
}

/**
 * @todo malloc die je niet beveiligt...
*/
bool	prep_flood(char **full_map)
{
	t_map	*flood;

	flood = malloc(sizeof(t_map));
	if (!flood)
		return (write(2, "Error\nFlood_malloc_fail\n", 25), true);
	flood->exit = 0;
	if (sus_player(full_map))
		return (free(flood), true);
	flood->exit = player(&flood, full_map);
	if (flood->exit)
		return (free(flood), true);
	flood_it(flood->player_x, flood->player_y, &flood, full_map);
	if (flood->exit)
		return (free(flood), true);
	free(flood);
	return (false);
}
