/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:36:35 by code              #+#    #+#             */
/*   Updated: 2024/01/14 20:08:39 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	txt_to_ptr(t_god *data)
{
	data->no_so_ea_we.no = data->textures_path[0] + 2;
	data->no_so_ea_we.so = data->textures_path[1] + 2;
	data->no_so_ea_we.ea = data->textures_path[2] + 2;
	data->no_so_ea_we.we = data->textures_path[3] + 2;
	return (false);
}
