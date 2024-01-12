/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:43 by code              #+#    #+#             */
/*   Updated: 2024/01/12 20:27:19 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	num_go_boom(t_colours *c)
{
	if (c->left < 0 || c->left > 255)
		return (true);
	if (c->middle < 0 || c->middle > 255)
		return (true);
	if (c->right < 0 || c->right > 255)
		return (true);
	return (false);
}

bool	convert_to_num(t_colours *c, char *str)
{
	size_t	i;
	char	**temp;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	temp = ft_split(str + i, ',');
	if (!temp)
		return (true);
	i = 0;
	while (temp[i])
		i++;
	if (i != 3)
		return (ft_free_s(temp), true);
	c->left = ft_atoi(temp[0]);
	c->middle = ft_atoi(temp[1]);
	c->right = ft_atoi(temp[2]);
	ft_free_s(temp);
	return (false);
}

bool	add_floor(t_god *data)
{
	size_t	i;

	i = 0;
	while (data->no_spaces_file && data->no_spaces_file[i])
	{
		if (data->no_spaces_file[i][0] == 'F')
			data->floor_str = data->no_spaces_file[i];
		if (data->no_spaces_file[i][0] == 'C')
			data->ceiling_str = data->no_spaces_file[i];
		i++;
	}
	if (convert_to_num(&data->ceiling, data->ceiling_str))
		return (true);
	if (convert_to_num(&data->floor, data->floor_str))
		return (true);
	if (num_go_boom(&data->ceiling))
		return (true);
	if (num_go_boom(&data->floor))
		return (true);
	return (false);
}

bool	tab_killer(char **full_map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!full_map)
		return (true);
	while (full_map[x])
	{
		while (full_map[x][y])
		{
			if (full_map[x][y] == '\t')
				return (true);
			y++;
		}
		y = 0;
		x++;
	}
	return (false);
}

bool	check_game_data(t_god *data, char **flood_me)
{
	bool	err;

	err = false;
	if (tab_killer(flood_me))
		return (true);
	if (dp_strlen(flood_me) <= 2)
		return (true);
	err = prep_flood(flood_me);
	err = add_floor(data);
	ft_free_s(flood_me);
	return (err);
}
