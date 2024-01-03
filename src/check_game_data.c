/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:43 by code              #+#    #+#             */
/*   Updated: 2024/01/03 19:19:08 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	tabs_to_spaces(char **full_map)
// {
// 	size_t	i;
// 	size_t	x;
// 	int		count;
	
// 	count = 0;
// 	x = 0;
// 	i = 0;
// 	while (full_map[i])
// 	{
// 		while (full_map[i][x])
// 		{
// 			if (full_map[i][x] == '\t')
// 				count = replace_tab(full_map[i]);
// 			x++;
// 			count++;
// 		}
// 		i++;
// 	}
// }

bool	r_side_walls(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == ' ')
			i--;
		if (str[i] == '1')
			return (false);
		else
			break;
	}
	return (true);
}

void	check_what_came_before(char *str, size_t x)
{
	while (x != 0)
	{
		if (str[x] != '1' || str[x] != ' ' || str[x] != '\t')
		{
			printf("wtf man\n");
			break ;
		}
		x--;
	}
}

size_t	l_side_walls(char *str, size_t x)
{
	size_t	i;

	if (x > 0)
	{
		check_what_came_before(str, x);
		i = x;
	}
	else
		i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			x = x + 4;
			i++;
			continue ;
		}
		if (str[i] == '1')
			return (x);
		else
			break;
	}
	return (x);
}

bool	garbage_map(t_god *data, bool err)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (data->full_map && data->full_map[i])
	{
		x = l_side_walls(data->full_map[i], x);
		i++;
	}
	return (err);
}
bool	floor_ceiling_data(t_god *data, bool err)
{
	(void) data;
	if (!err)
		return (err);
	
	return (err);
}

bool	texture_path_data(t_god *data, bool err)
{
	(void) data;
	if (!err)
		return (err);
	
	return (err);
}
bool	map_data(t_god *data, bool err)
{
	(void) data;
	if (!err)
		return (err);
	
	return (err);
}

bool	flood_fill(t_god *data, bool err)
{
	(void) data;
	if (!err)
		return (err);
	
	return (err);
}

bool	check_game_data(t_god *data)
{
	bool	err = false;

	// tabs_to_spaces(data->full_map);
	err = garbage_map(data, err);
	err = floor_ceiling_data(data, err);
	err = texture_path_data(data, err);
	err = map_data(data, err);
	err = flood_fill(data, err);
	return (err);
}