/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:02:31 by code              #+#    #+#             */
/*   Updated: 2023/12/13 14:07:01 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	check_file_extension(char *str)
{
	char	check[5];
	
	ft_strlcpy(check, str+ft_strlen(str)-4, 5);
	if (!ft_strncmp(check, ".cub", 5))
		return ;
	else
	{
		write(2, "check file name\n", 17);
		exit(2);
	}
}


int	location(char **full_map, char *str)
{
	int	i;

	i = 0;
	if (!full_map)
		return (-1);
	while (full_map[i])
	{
		if (!ft_memcmp(str, full_map[i], ft_strlen(str)))
			break;
		i++;
	}
	return (i);
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


int	main(int argc, char **argv)
{
	t_god			*game_data;

	if (argc != 2)
		exit((write(2, "Error\ncheck input\n", 18)));
	check_file_extension(argv[1]);
	game_data = malloc(sizeof(t_god));
	game_data->no_spaces_file = parse(argv[1], game_data);
	game_data->full_map = &game_data->no_spaces_file[6];
	if (!search_correct_type(game_data))
		exit (2);
	// test_parse_data(game_data);
	free_all(game_data);




	// check_map(game_data->full_map);
	// game_data->collectables = prep_flood(temp);
	// ft_free_s(temp);
	// build_game(&game_data);
	// mlx_key_hook(game_data->mlx, &run_game, game_data);
	// mlx_loop(game_data->mlx);
	// mlx_terminate(game_data->mlx);
	// ft_free_s(game_data->full_map);
	return (0);
}