/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:01:38 by code              #+#    #+#             */
/*   Updated: 2023/12/02 14:45:47 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct map_tiles
{
	char	**map;
	int		player_x;
	int		player_y;
	int		exit;
	int		collectables;
}t_map;

typedef struct game_textures
{
	mlx_image_t		*i_player;
	mlx_image_t		*i_exit;
	mlx_image_t		*i_floor;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_joint;
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_joint;
}t_game;

typedef struct g_struct
{
	char	**full_map;
	int		line_number_map;
	int		line_number_c_f;
	int		line_number_texture_path;
	// int		collectables;
	// t_game	*textures;
	// mlx_t	*mlx;
	// int		p_x;
	// int		p_y;
	// int		moves;
}t_god;


void    test_parse_data(t_god *data);
char	**parse(char ***temp, char *map_input);



#endif