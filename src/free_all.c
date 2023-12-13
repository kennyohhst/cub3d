/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:08:11 by code              #+#    #+#             */
/*   Updated: 2023/12/10 18:12:05 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_all(t_god *data)
{
	int	i;

	i = 0;
	if (data)
	{
		while (data->no_spaces_file[i])
			free(data->no_spaces_file[i++]);

		free(data->no_spaces_file);
		free(data->floor_ceiling[0]);
		free(data->floor_ceiling[1]);

		free(data->textures_path[0]);
		free(data->textures_path[1]);
		free(data->textures_path[2]);
		free(data->textures_path[3]);

	}
	free(data);
	// printf("hi\n");
}