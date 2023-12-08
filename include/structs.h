/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:15:49 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2023/12/08 16:50:06 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct map_tiles
{
	char			**map;
	int				player_x;
	int				player_y;
}					t_map;

typedef struct game_textures
{
	// mlx_texture_t	*t_exit;
	// mlx_texture_t	*door_n;
	// mlx_texture_t	*door_s;
	// mlx_texture_t	*door_e;
	// mlx_texture_t	*door_w;
	mlx_texture_t	*t_floor;
	mlx_texture_t	*t_sky;
	mlx_texture_t	*t_wall_n;
	mlx_texture_t	*t_wall_s;
	mlx_texture_t	*t_wall_e;
	mlx_texture_t	*t_wall_w;
}					t_game;

typedef struct live_data
{
	int				p_x;
	int				p_y;
	double			fov;
	double			camera_x;
	mlx_t			*mlx;
}					t_mlx;

typedef struct g_struct
{
	char			**full_map;
	int				line_number_map;
	int				line_number_c_f;
	int				line_number_texture_path;
	// int		collectables;
	// t_game	*textures;
	// mlx_t	*mlx;
	// int		p_x;
	// int		p_y;
	// int		moves;
}					t_god;