/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkalika <kkalika@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:01:38 by code          #+#    #+#                 */
/*   Updated: 2023/12/08 16:15:47 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>

# define PIXEL 64

void	test_parse_data(t_god *data);
char	**parse(char ***temp, char *map_input);

#endif