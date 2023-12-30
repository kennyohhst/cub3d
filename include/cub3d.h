/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkalika <kkalika@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:01:38 by code          #+#    #+#                 */
/*   Updated: 2023/12/29 12:20:04 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "render.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>

// void	test_parse_data(t_god *data);
// char	**parse(char ***temp, char *map_input);

int32_t	get_RGB(int r, int g, int b);

#endif