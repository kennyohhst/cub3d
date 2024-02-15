/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/09 11:13:37 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/02/15 12:53:56 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures(t_render *game, t_god *p)
{
	game->text.t_wall_n = mlx_load_png(p->no_so_ea_we.no + 1);
	if (!game->text.t_wall_n)
	{
		write(2, "Error: MLX_load_png: North_wall\n", 33);
		exit(1);
	}
	game->text.t_wall_s = mlx_load_png(p->no_so_ea_we.so + 1);
	if (!game->text.t_wall_s)
	{
		write(2, "Error: MLX_load_png: South_wall\n", 33);
		exit(1);
	}
	game->text.t_wall_e = mlx_load_png(p->no_so_ea_we.ea + 1);
	if (!game->text.t_wall_e)
	{
		write(2, "Error: MLX_load_png: East_wall\n", 32);
		exit(1);
	}
	game->text.t_wall_w = mlx_load_png(p->no_so_ea_we.we + 1);
	if (!game->text.t_wall_w)
	{
		write(2, "Error: MLX_load_png: West_wall\n", 32);
		exit(1);
	}
}

void init_raycasting(t_render *game)
{
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
}

void	set_radian_init_bckgrnd(t_render *game)
{
	if (game->map[(int)game->player.py][(int)game->player.px] == 'N')
		game->player.rad = 1.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'E')
		game->player.rad = 0 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'S')
		game->player.rad = 0.5 * PI;
	if (game->map[(int)game->player.py][(int)game->player.px] == 'W')
		game->player.rad = 1 * PI;
	game->text.img_backgrnd = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->text.img_backgrnd)
	{
		write(2, "Error: MLX_new_image: background\n", 29);
		exit(1);
	}
}


void	get_player_position(t_render *game)
{
	int x = 0;
	int y = 0;

	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'N' || game->map[x][y] == 'E' ||
				game->map[x][y] == 'S' || game->map[x][y] == 'W')
			{
				game->player.px = y;
				game->player.py = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

t_render	*init_render(t_god *p)
{
	t_render *game;

	game = ft_calloc(1, sizeof(t_render));
	if (!game)
		exit(1);
	game->map = p->full_map;
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
	{
		write(2, "Error: MLX_init\n", 17);
		exit(1);
	}
	get_player_position(game);
	set_radian_init_bckgrnd(game);
	printf("rgb floor: r: %d g: %d b: %d\n", p->floor.left, p->floor.middle, p->floor.right);
	printf("rgb ceiling: r: %d g: %d b: %d\n", p->ceiling.left, p->ceiling.middle, p->ceiling.right);


	game->text.floor_color = get_RGB(255, p->floor.left, p->floor.middle, p->floor.right);
	game->text.ceiling_color = get_RGB(255, p->ceiling.left, p->ceiling.middle, p->ceiling.right);
	init_textures(game, p);
	init_raycasting(game);
	game->parse_data = p;
	return (game);
}
