/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:59:46 by kkalika           #+#    #+#             */
/*   Updated: 2024/01/14 20:12:21 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	run_floor_ceiling(char **f_c)
// {
// 	int	i;

// 	i = 0;
// 	if (!f_c)
// 	{
// 		printf("NSF is nothing\n");
// 		return ;
// 	}
// 	printf("----------------floor_ceiling:---------------------------\n\n");
// 	while (f_c[i])
// 		printf("			%s\n", f_c[i++]);
// 	printf("\n---------------------------------------------------------\n");
// }

void	run_floor_ceiling_ints(t_god *data)
{
	if (!data)
	{
		printf("there is no data buddy\n");
		return ;
	}
	printf("----------------floor_ceiling:---------------------------\n\n");
	printf("\nceiling: %d.%d.%d\n", data->ceiling.left,
		data->ceiling.middle, data->ceiling.right);
	printf("\nfloor: %d.%d.%d\n", data->floor.left,
		data->floor.middle, data->floor.right);
	printf("\n---------------------------------------------------------\n");
}

void	run_textures_path(char **t_p, t_god *data)
{
	int	i;

	i = 0;
	if (!t_p)
	{
		printf("NSF is nothing\n");
		return ;
	}
	printf("----------------textures_path:---------------------------\n\n");
	while (t_p[i])
		printf("			%s\n", t_p[i++]);
	printf("\n---------------------------------------------------------\n");
	printf("----------------textures_path_2:-------------------------\n\n");
	printf("%s\n", data->no_so_ea_we.no);
	printf("%s\n", data->no_so_ea_we.so);
	printf("%s\n", data->no_so_ea_we.ea);
	printf("%s\n", data->no_so_ea_we.we);
	printf("\n---------------------------------------------------------\n");
}

void	run_only_map(char **om)
{
	int	i;

	i = 0;
	if (!om)
	{
		printf("NSF is nothing\n");
		return ;
	}
	printf("----------------Only map:--------------------------------\n\n");
	while (om && om[i])
	{
		printf("%s\n", om[i]);
		i++;
	}
	printf("\n---------------------------------------------------------\n");
}

void	run_no_spaces_file(char **nsf)
{
	int	i;

	i = 0;
	if (!nsf)
	{
		printf("NSF is nothing\n");
		return ;
	}
	printf("----------------no_spaces_file:--------------------------\n\n");
	while (nsf[i])
		printf("			%s\n", nsf[i++]);
	printf("\n---------------------------------------------------------\n");
}

void	test_parse_data(t_god *data)
{
	t_god	*temp;

	if (!data)
	{
		write(1, "Data is empty\n", 15);
		return ;
	}
	temp = data;
	run_no_spaces_file(temp->no_spaces_file);
	run_only_map(temp->full_map);
	run_floor_ceiling_ints(data);
	run_textures_path(data->textures_path, data);
}
