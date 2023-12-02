/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:02:31 by code              #+#    #+#             */
/*   Updated: 2023/12/02 15:13:25 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		// printf("string = %s\ni = %d\n", full_map[i], i);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	// (void) argv;
	t_god			*game_data;
	char			**temp;

	
	if (argc != 2)
		exit((write(2, "Error\ncheck input\n", 18)));
	game_data = malloc(sizeof(t_god));
	// game_data->textures = malloc(sizeof(t_game));
	// if (!game_data || !game_data->textures)
	// 	exit(write(2, "error\ngame/full_map error\n", 26));
	game_data->full_map = parse(&temp, argv[1]);
	game_data->line_number_texture_path = location(game_data->full_map, "NO ");
	game_data->line_number_c_f = location(game_data->full_map, "F ");
	game_data->line_number_map = location(game_data->full_map, "1");
	test_parse_data(game_data);
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