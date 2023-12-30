/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:15:49 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2023/12/30 16:55:22 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>

typedef struct map_tiles
{
	char			**map;
	int				player_x;
	int				player_y;
}					t_map;

typedef struct s_game_textures
{
	// mlx_texture_t	*t_exit;
	// mlx_texture_t	*door_n;
	// mlx_texture_t	*door_s;
	// mlx_texture_t	*door_e;
	// mlx_texture_t	*door_w;
	int32_t			floor_color;
	int32_t			ceiling_color;
	mlx_image_t		*img_background;
	mlx_image_t		*img_walls;
	mlx_texture_t	*t_wall_n;
	mlx_texture_t	*t_wall_s;
	mlx_texture_t	*t_wall_e;
	mlx_texture_t	*t_wall_w;
}					t_text;

typedef struct s_player_data
{
	int				px;
	int				py;
	double			pd;
}					t_player;

typedef struct s_screen
{
	int32_t			width;
	int32_t			height;
}					t_screen;

typedef struct s_render
{
	char			**map;
	mlx_t			*mlx;
	t_player		player;
	t_screen		screen;
	t_text			text;
}					t_render;

// typedef struct g_struct
// {
// 	char			**full_map;
// 	int				line_number_map;
// 	int				line_number_c_f;
// 	int				line_number_texture_path;
// 	// int		collectables;
// 	// t_game	*textures;
// 	// mlx_t	*mlx;
// 	// int		p_x;
// 	// int		p_y;
// 	// int		moves;
// }					t_god;