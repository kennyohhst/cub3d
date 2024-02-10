/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/10 16:56:03 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/10 18:36:18 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include "../lib/mlx42/include/MLX42/MLX42.h"

/* structs used for parsing*/

/**
 * @brief strings refering to the textures
 */
typedef struct txtrs
{
	char *no;
	char *so;
	char *ea;
	char *we;
} t_txtrs;

/**
 * @brief RGB colours
 */
typedef struct colours
{
	int left;
	int middle;
	int right;
} t_colours;

/**
 * @brief map player position
 */
typedef struct map_tiles
{
	int player_x;
	int player_y;
	bool exit;
} t_map;

/**
 * @brief god struct containing general data
 */
typedef struct g_struct
{
	char **no_spaces_file;
	char **full_map;
	char *textures_path[5];
	char *floor_ceiling[3];
	char *floor_str;
	char *ceiling_str;
	t_colours floor;
	t_colours ceiling;
	t_txtrs no_so_ea_we;
} t_god;

/* structs related to rendering of the game */

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

/**
 * @brief the colours, textures and the mlx_image to place the pixels
 */
typedef struct s_game_textures
{
	int32_t floor_color;
	int32_t ceiling_color;
	mlx_texture_t *t_wall_n;
	mlx_texture_t *t_wall_s;
	mlx_texture_t *t_wall_e;
	mlx_texture_t *t_wall_w;
	mlx_image_t *img_backgrnd;
} t_text;

/**
 * @param distance	dist for each ray
 * @param wall_side	side of the wall that was hit
 * @param wall_h	the exact x position the wall was hit
 * @note			wall_side is defined by NORTH EAST SOUTH WEST
 */
typedef struct s_raycasting
{
	double *distance;
	int *wall_side;
	double *wall_h;
} t_raycasting;

/**
 * @brief player position & radian view angle
 */
typedef struct s_player_data
{
	double px;
	double py;
	double rad;
} t_player;

/**
 * @brief main struct for rendering
 */
typedef struct s_render
{
	char **map;
	mlx_t *mlx;
	t_player player;
	t_text text;
	t_raycasting cast;
	t_god	*parse_data;
} t_render;

/**
 * @brief struct used in distance calculation
 */
typedef struct s_local_calc
{
	size_t cast_n;
	double radian;
	double hor_ray_x;
	double hor_ray_y;
	double hor_stepx;
	double hor_stepy;
	double ver_ray_x;
	double ver_ray_y;
	double ver_stepx;
	double ver_stepy;
	double distance;
} t_calc;

#endif /* STRUCTS_H */