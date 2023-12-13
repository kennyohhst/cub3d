/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:43 by kkalika           #+#    #+#             */
/*   Updated: 2023/12/13 14:05:50 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**parse(char *map_input, t_god *data)
{
	int		fd;
	char	*temp_str;
	char	*str;
	char	**no_spaces_file;
	
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
	no_spaces_file = ft_split(str, '\n');
	data->full_map = &no_spaces_file[6];
	free(str);
	close(fd);
	return (no_spaces_file);
}
