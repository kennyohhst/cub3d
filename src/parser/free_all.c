/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_all.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: code <code@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/10 16:08:11 by code          #+#    #+#                 */
/*   Updated: 2024/02/10 17:59:22 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
}
