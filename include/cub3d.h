/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkalika <kkalika@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:01:38 by code          #+#    #+#                 */
/*   Updated: 2024/02/02 15:19:50 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "game_settings.h"
#include "structs.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

// void	test_parse_data(t_god *data);
// char	**parse(char ***temp, char *map_input);

t_render	*init_render(void);

uint32_t get_RGB(int a, int r, int g, int b);
void	sl_hooks(void *param);

void	walls_main(void *game_data);
void	calc_distance(t_render *game);
void	calc_pixels(t_render *game);

#endif