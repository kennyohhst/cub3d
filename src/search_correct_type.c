/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_correct_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:16:27 by code              #+#    #+#             */
/*   Updated: 2023/12/25 16:58:06 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	one_of_each(char **full_map, char *c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (full_map[i])
	{
		if (!ft_memcmp(c, full_map[i], 2))
			x++;
		if (x > 1)
		{
			write(2, "Error\none_of_each_1\n", 20);
			exit(2);
		}
		i++;
	}
}

void	double_data(t_god *game_data)
{
	one_of_each(game_data->no_spaces_file, "NO");
	one_of_each(game_data->no_spaces_file, "SO");
	one_of_each(game_data->no_spaces_file, "WE");
	one_of_each(game_data->no_spaces_file, "EA");
	one_of_each(game_data->no_spaces_file, "F ");
	one_of_each(game_data->no_spaces_file, "C ");
}

int	search_correct_type(t_god *data)
{
	char	**temp;
	int		i;

	i = 0;
	temp = data->no_spaces_file;
	while (temp[i] && i < 6)
	{
		if (!ft_memcmp("NO", temp[i], 2))
			data->textures_path[0] = ft_strdup(temp[i]);
		else if (!ft_memcmp("SO", temp[i], 2))
			data->textures_path[1] = ft_strdup(temp[i]);
		else if (!ft_memcmp("EA", temp[i], 2))
			data->textures_path[2] = ft_strdup(temp[i]);
		else if (!ft_memcmp("WE", temp[i], 2))
			data->textures_path[3] = ft_strdup(temp[i]);
		else if (!ft_memcmp("F ", temp[i], 2))
			data->floor_ceiling[0] = ft_strdup(temp[i]);
		else if (!ft_memcmp("C ", temp[i], 2))
			data->floor_ceiling[1] = ft_strdup(temp[i]);
		i++;
		double_data(data);
	}
	data->textures_path[4] = NULL;
	data->floor_ceiling[2] = NULL;
	return (1);
}
