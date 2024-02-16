/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:02:31 by code              #+#    #+#             */
/*   Updated: 2024/02/16 15:04:03 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @todo malloc die je niet beveiligt...
*/
char	**double_array_copy(char **array)
{
	char	**return_array;
	size_t	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	return_array = malloc((i + 1) * sizeof(char *));
	if (!return_array)
		return (NULL);
	return_array[i] = NULL;
	i = 0;
	while (array[i])
	{
		return_array[i] = ft_strdup(array[i]);
		if (!return_array[i])
			return (NULL);
		i++;
	}
	return (return_array);
}

int	main(int argc, char **argv)
{
	t_god	*game_data;
	char	**temp;

	if (argc != 2)
		return (write(2, "Error\nmissing input\n", 21), 1);
	check_file_extension(argv[1]);
	game_data = malloc(sizeof(t_god));
	if (!game_data)
		return (write(2, "Error\nmalloc failed\n", 21), 1);
	game_data->no_spaces_file = parse(argv[1], game_data);
	if (!game_data->no_spaces_file)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	temp = double_array_copy(game_data->full_map);
	if (check_game_data(game_data, temp))
		exit(1);
	render_main(game_data);
	free_all(game_data);
	return (0);
}
