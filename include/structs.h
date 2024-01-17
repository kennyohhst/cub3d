/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:15:49 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/01/17 22:20:23 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

typedef struct map_tiles
{
	char			**map;
	int				player_x;
	int				player_y;
}					t_map;

typedef struct s_game_textures
{
	int32_t			floor_color;
	int32_t			ceiling_color;
	mlx_texture_t	*t_wall_n;
	mlx_texture_t	*t_wall_s;
	mlx_texture_t	*t_wall_e;
	mlx_texture_t	*t_wall_w;
	mlx_image_t		*img_background;
	mlx_image_t		*img_walls;
}					t_text;

/**
 * @param total_pixels	is total amount of pixels in a fullscreen image
 * @param ray_steps 	is the size to go from one ray to the next;

			* @param distance		distance from the player position to each wall for each ray;
 * @param wall_side		the side of the wall that each ray hit, NORTH, EAST,
			SOUTH, WEST
 * @param pixels_buffer	the pixels to be placed in the img_walls;
 */
typedef struct s_raycasting
{
	size_t			total_pixels;
	double			ray_steps;
	double			*distance;
	int				*wall_side;
	double			*wall_h;
	uint8_t			*pixels_buffer;
}					t_raycasting;

typedef struct s_player_data
{
	double				px;
	double				py;
	double				rad;
}					t_player;

// typedef struct s_screen
// {
// 	int32_t			width;
// 	int32_t			height;
// }					t_screen;

typedef struct s_render
{
	char			**map;
	mlx_t			*mlx;
	t_player		player;
	t_text			text;
	t_raycasting	cast;
	// t_screen		screen;
}					t_render;


/**
 * @param cast_n is the current ray
 * @param radian is the current radian
 * @param mapx is x coordinate of the wall that was hit
 * @param mapy is y coordinate of the wall that was hit
 * @param wall_h is the exact value of where the wall was hit 0.0 - 1.0
 * @param wall_side is the side of the wall that was hit - NORTH, EAST, SOUTH,
	WEST
 * @param stepx is the step in x direction
 * @param stepy is the step in y direction
 * @param sidedistx is the distance to the next x side
 * @param sidedisty is the distance to the next y side
 */
typedef struct s_local_dda
{
	size_t		cast_n;
	double		radian;
	double		mapx;
	double		mapy;
	double		wall_h;
	int			wall_side;
	double		deltaX;
	double		deltaY;
	double		stepx;
	double		stepy;
	double		sidedistx;
	double		sidedisty;
}				t_dda;

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