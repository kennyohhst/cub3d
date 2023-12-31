/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:01:38 by code              #+#    #+#             */
/*   Updated: 2023/12/25 16:49:19 by code             ###   ########.fr       */
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
	char	**no_spaces_file;
	char	**full_map;
	char	*textures_path[5];
	char	*floor_ceiling[3];
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
char	**parse(char *map_input, t_god *data);
void	one_of_each(char **full_map, char *c);
void	free_all(t_god *data);
bool	check_game_data(t_god *data);
void	check_file_extension(char *str);
void	double_data(t_god *game_data);
int		search_correct_type(t_god *data);
int		dp_strlen(char **str);





#endif