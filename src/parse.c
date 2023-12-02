/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:43 by kkalika           #+#    #+#             */
/*   Updated: 2023/12/02 14:45:07 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**parse(char ***temp, char *map_input)
{
	int		fd;
	char	*temp_str;
	char	*str;
	char	**full_map;

	str = NULL;
	fd = open(map_input, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Error\nfd\n", 9));
	temp_str = get_next_line(fd);
	while (temp_str)
	{
		str = strljoin(str, temp_str, ft_strlen(temp_str), 0);
		free(temp_str);
		temp_str = get_next_line(fd);
	}
	full_map = ft_split(str, '\n');
	(*temp) = ft_split(str, '\n');
	free(str);
	close(fd);
	return (full_map);
}
