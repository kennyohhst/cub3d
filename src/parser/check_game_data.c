/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:21:43 by code              #+#    #+#             */
/*   Updated: 2024/02/16 19:44:49 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

	i = 1;
	if ((str[i++] != ' '))
		return (true);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			if (str[i] != ',')
				return (true);
		i++;
	}
	temp = ft_split(str + 2, ',');
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
	return (ft_free_s(temp), false);
}

bool	add_floor_ceiling(t_god *data)
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
	if (convert_to_num(&data->ceiling, data->ceiling_str)
		|| num_go_boom(&data->ceiling) || convert_to_num(&data->floor,
			data->floor_str) || num_go_boom(&data->floor))
		return (true);
	return (false);
}

bool	thing_in_map(char **full_map)
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
			if (full_map[x][y] != '1' && 
				full_map[x][y] != '0' && 
				full_map[x][y] != 'W' && full_map[x][y] != 'E' && 
				full_map[x][y] != 'N' && full_map[x][y] != 'S'
				&& full_map[x][y] != ' ')
				return (write(2, "Error\nThing in map\n", 20), true);
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
	if (thing_in_map(flood_me))
		return (true);
	if (dp_strlen(flood_me) <= 2)
		return (true);
	if (prep_flood(flood_me))
		return (true);
	if (search_correct_type(data))
		return (true);
	if (add_floor_ceiling(data))
		return (true);
	err = txt_to_ptr(data);
	ft_free_s(flood_me);
	return (err);
}
