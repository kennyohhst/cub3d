/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:43 by code              #+#    #+#             */
/*   Updated: 2023/12/20 16:59:46 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


bool	garbage_map(t_god *data, bool err)
{
	// (void) data;
	int	i;

	i = 0;
	while (data->no_spaces_file && data->no_spaces_file[i])
	{
		
		printf("data->no_spaces_file %s\n", data->no_spaces_file[i++]);
	}
	if (!err)
		return (err);
	
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

	err = garbage_map(data, err);
	err = floor_ceiling_data(data, err);
	err = texture_path_data(data, err);
	err = map_data(data, err);
	err = flood_fill(data, err);
	return (err);
}