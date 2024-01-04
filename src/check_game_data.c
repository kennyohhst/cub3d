/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:43 by code              #+#    #+#             */
/*   Updated: 2024/01/04 20:15:10 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*replace_instance(char	*src, char	*dst, size_t si, size_t di)
{
	while (src[si] && dst[di])
	{
		dst[di] = src[si];
		di++;
		si++;
	}
	dst[di] = '\0';
	return (dst);
}

char	*convert_tab_to_space(char *str, size_t i, size_t count)
{
	char	*temp;
	size_t		x;
	
	x = 0;
	if (count <= 0)
		count = 4;
	temp = malloc(ft_strlen(str) + count);
	if (!temp)
		return (free(str), NULL);
	while (str[x])
	{
		if (x == i)
		{
			i++;
			while (count--)
				temp[x++] = ' ';
			temp = replace_instance(str, temp, i, x);
			return (free(str), temp);
		}
		temp[x] = str[x];
		x++; 
	}
	return (temp);
}


char	*scan_for_tabs(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 4;
	while (str && str[i])
	{
		if (str[i] == '\t')
		{
			str = convert_tab_to_space(str, i, count);
			if (!str)
				return (NULL);
			count = 4;
			i = 0;
		}
		if (count <= 0)
			count = 4;
		else
			count--;
		i++;
	}
	return (str);
}

bool	tabs_spaces_check_map(t_god *data, bool err)
{
	size_t	i;
	size_t	x;
	char	**temp;

	temp = data->full_map;
	i = 0;
	x = 0;
	while (temp && temp[i])
	{
		temp[i] = scan_for_tabs(temp[i]);
		if (!temp[i])
			return (err);
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
	prep_flood(data->full_map);
	return (err);
}

bool	check_game_data(t_god *data)
{
	bool	err = false;

	// tabs_to_spaces(data->full_map);
	err = tabs_spaces_check_map(data, err);
	
	// err = flood_fill(data, err);
	// err = floor_ceiling_data(data, err);
	// err = texture_path_data(data, err);
	// err = map_data(data, err);
	return (err);
}