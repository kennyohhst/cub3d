/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:01:38 by code              #+#    #+#             */
/*   Updated: 2024/02/10 16:29:54 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../lib/mlx42/include/MLX42/MLX42.h"

typedef struct txtrs
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}t_txtrs;

typedef struct colours
{
	int	left;
	int	middle;
	int	right;
}t_colours;

typedef struct map_tiles
{
	int		player_x;
	int		player_y;
	bool	exit;
}t_map;

typedef struct g_struct
{
	char		**no_spaces_file;
	char		**full_map;
	char		*textures_path[5];
	char		*floor_ceiling[3];
	char		*floor_str;
	char		*ceiling_str;
	t_colours	floor;
	t_colours	ceiling;
	t_txtrs		no_so_ea_we;
}t_god;

void    test_parse_data(t_god *data);
char	**parse(char *map_input, t_god *data);
void	free_all(t_god *data);
bool	check_game_data(t_god *data, char **flood_me);
void	check_file_extension(char *str);
bool	search_correct_type(t_god *data);
int		dp_strlen(char **str);
bool	prep_flood(char **full_map);
void	ft_free_s(char **string);
bool	txt_to_ptr(t_god *data);

#endif