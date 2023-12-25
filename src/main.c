/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:02:31 by code              #+#    #+#             */
/*   Updated: 2023/12/25 16:57:53 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_god			*game_data;

	if (argc != 2)
		exit((write(2, "Error\ncheck input\n", 18)));
	check_file_extension(argv[1]);
	game_data = malloc(sizeof(t_god));
	game_data->no_spaces_file = parse(argv[1], game_data);
	if (!search_correct_type(game_data))
		exit (2);
	test_parse_data(game_data);
	free_all(game_data);
	return (0);
}
