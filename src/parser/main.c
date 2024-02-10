/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: code <code@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:02:31 by code          #+#    #+#                 */
/*   Updated: 2024/02/10 18:04:40 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	return_array[i] = NULL;
	i = 0;
	while (array[i])
	{
		return_array[i] = ft_strdup(array[i]);
		i++;
	}
	return (return_array);
}

int	main(int argc, char **argv)
{
	t_god			*game_data;
	char			**temp;

	if (argc != 2)
		exit((write(2, "Error\ncheck input\n", 19)));
	check_file_extension(argv[1]);
	game_data = malloc(sizeof(t_god));
	game_data->no_spaces_file = parse(argv[1], game_data);
	temp = double_array_copy(game_data->full_map);
	if (check_game_data(game_data, temp))
		exit(write(2, "Error_map_not_good\n", 20));
	test_parse_data(game_data);
	render_main(game_data);
	free_all(game_data);
	return (0);
}
