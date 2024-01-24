/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: julius <julius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 12:19:43 by julius        #+#    #+#                 */
/*   Updated: 2024/01/24 08:16:08 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * @brief creates a 32 bit integer from RGB values
 * @param a alpha
 * @param r red
 * @param g green
 * @param b blue
*/
uint32_t	get_RGB(int a, int r, int g, int b)
{
	return ((a << 24) | (b << 16) | (g << 8) | r);
}


void	init_textures(t_render *game)
{
	game->text.img_background = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_background)
	{
		write(2, "Error: MLX_new_image: background\n", 34);
		exit(1);
	}
	game->text.img_walls = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_walls)
	{
		write(2, "Error: MLX_new_image: walls\n", 29);
		exit(1);
	}
	game->text.t_wall_n = mlx_load_png("./texture/North_wall.png");
	if (!game->text.t_wall_n)
	{
		write(2, "Error: MLX_load_png: North_wall\n", 33);
		exit(1);
	}
	game->text.t_wall_s = mlx_load_png("./texture/South_wall.png");
	if (!game->text.t_wall_s)
	{
		write(2, "Error: MLX_load_png: South_wall\n", 33);
		exit(1);
	}
	game->text.t_wall_e = mlx_load_png("./texture/East_wall.png");
	if (!game->text.t_wall_e)
	{
		write(2, "Error: MLX_load_png: East_wall\n", 32);
		exit(1);
	}
	game->text.t_wall_w = mlx_load_png("./texture/West_wall.png");
	if (!game->text.t_wall_w)
	{
		write(2, "Error: MLX_load_png: West_wall\n", 32);
		exit(1);
	}
	game->text.ceiling_color = get_RGB(255, 173, 216, 230);
	game->text.floor_color = get_RGB(255, 76, 28, 36);
}

void init_raycasting(t_render *game)
{
	game->cast.total_pixels = WIDTH * HEIGHT;
	game->cast.distance = malloc(sizeof(double) * WIDTH);
	if (!game->cast.distance)
	{
		write(2, "Error: malloc: distance\n", 25);
		exit(1);
	}
	game->cast.wall_side = malloc(sizeof(int) * WIDTH);
	if (!game->cast.wall_side)
	{
		write(2, "Error: malloc: wall_side\n", 26);
		exit(1);
	}
	game->cast.wall_h = malloc(sizeof(double) * WIDTH);
	if (!game->cast.wall_h)
	{
		write(2, "Error: malloc: wall_h\n", 23);
		exit(1);
	}
	game->cast.pixels_buffer = malloc(sizeof(int32_t) * WIDTH * HEIGHT);
	if (!game->cast.pixels_buffer)
	{
		write(2, "Error: malloc: pixels_buffer\n", 30);
		exit(1);
	}
}

void	set_radian(t_render *game)
{
	if (game->map[(int)game->player.py][(int)game->player.px] == 'N')
		game->player.rad = 1.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'E')
		game->player.rad = 0 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'S')
		game->player.rad = 0.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'W')
		game->player.rad = 1 * PI;
}

t_render	*init_render(void)
{
	t_render *game;

	game = ft_calloc(1, sizeof(t_render));
	if (!game)
		exit(1);
	char **set_map = malloc(sizeof(char *) * 9);  // 9 is the number of rows in your map
	if (!set_map)
	{
	    write(2, "Error: malloc: set_map\n", 23);
 	   exit(1);
	}

	set_map[0] = ft_strdup("11111");
	set_map[1] = ft_strdup("10001");
	set_map[2] = ft_strdup("10001");
	set_map[3] = ft_strdup("10101");
	set_map[4] = ft_strdup("10001");
	set_map[5] = ft_strdup("10N01");
	set_map[6] = ft_strdup("10001");
	set_map[7] = ft_strdup("11111");
	set_map[8] = NULL;  // NULL-terminate the array

	game->map = set_map;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		write(2, "Error: MLX_init\n", 17);
		exit(1);
	}
	game->player.px = 2.5;
	game->player.py = 5.5;
	// game->player.planex = 1.0;
	// game->player.planey = 0.0;
	set_radian(game);
	init_textures(game);
	init_raycasting(game);
	return (game);
}
