/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 11:13:37 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/16 15:59:22 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_textures(t_render *game, t_god *p)
{
	game->text.t_wall_n = mlx_load_png(p->no_so_ea_we.no + 1);
	if (!game->text.t_wall_n)
	{
		write(2, "Error\nMLX_load_png: North_wall\n", 32);
		exit(1);
	}
	game->text.t_wall_s = mlx_load_png(p->no_so_ea_we.so + 1);
	if (!game->text.t_wall_s)
	{
		write(2, "Error\nMLX_load_png: South_wall\n", 32);
		exit(1);
	}
	game->text.t_wall_e = mlx_load_png(p->no_so_ea_we.ea + 1);
	if (!game->text.t_wall_e)
	{
		write(2, "Error\nMLX_load_png: East_wall\n", 31);
		exit(1);
	}
	game->text.t_wall_w = mlx_load_png(p->no_so_ea_we.we + 1);
	if (!game->text.t_wall_w)
	{
		write(2, "Error\nMLX_load_png: West_wall\n", 31);
		exit(1);
	}
}

static void	init_raycasting(t_render *game)
{
	game->text.img_backgrnd = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_backgrnd)
	{
		write(2, "Error\nMLX_new_image: background\n", 33);
		exit(1);
	}
	game->cast.distance = malloc(sizeof(double) * WIDTH);
	if (!game->cast.distance)
	{
		write(2, "Error\nmalloc: distance\n", 24);
		exit(1);
	}
	game->cast.wall_side = malloc(sizeof(int) * WIDTH);
	if (!game->cast.wall_side)
	{
		write(2, "Error\nmalloc: wall_side\n", 25);
		exit(1);
	}
	game->cast.wall_h = malloc(sizeof(double) * WIDTH);
	if (!game->cast.wall_h)
	{
		write(2, "Error\nmalloc: wall_h\n", 22);
		exit(1);
	}
}

static void	set_radian(t_render *game)
{
	if (game->map[(int)game->player.py][(int)game->player.px] == 'N')
		game->player.rad = 1.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'E')
		game->player.rad = 0 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'S')
		game->player.rad = 0.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'W')
		game->player.rad = 1 * PI;
	game->map[(int)game->player.py][(int)game->player.px] = '0';
}

static void	get_player_position(t_render *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'N' || game->map[x][y] == 'E'
				|| game->map[x][y] == 'S' || game->map[x][y] == 'W')
			{
				game->player.px = y;
				game->player.py = x;
				set_radian(game);
				return ;
			}
			y++;
		}
		x++;
	}
}

t_render	*init_render(t_god *p)
{
	t_render	*game;

	game = ft_calloc(1, sizeof(t_render));
	if (!game)
	{
		write(2, "Error\nmalloc t_render\n", 23);
		exit(1);
	}
	game->map = p->full_map;
	get_player_position(game);
	game->text.floor_color = get_rgb(255, p->floor.left, p->floor.middle,
			p->floor.right);
	game->text.ceiling_color = get_rgb(255, p->ceiling.left, p->ceiling.middle,
			p->ceiling.right);
	init_textures(game, p);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		write(2, "Error\nMLX_init\n", 16);
		exit(1);
	}
	init_raycasting(game);
	game->parse_data = p;
	return (game);
}
