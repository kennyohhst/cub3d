/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: code <code@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:01:38 by code          #+#    #+#                 */
/*   Updated: 2024/02/15 13:11:39 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "game_settings.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define PIXEL 64
# define PI 3.14159265358979323846
# define PI2 1.57079632679489661923
# define PI3 4.71238898038468985769

void		test_parse_data(t_god *data);
char		**parse(char *map_input, t_god *data);
void		free_all(t_god *data);
bool		check_game_data(t_god *data, char **flood_me);
void		check_file_extension(char *str);
bool		search_correct_type(t_god *data);
int			dp_strlen(char **str);
bool		prep_flood(char **full_map);
void		ft_free_s(char **string);
bool		txt_to_ptr(t_god *data);

/* render functions */
void		render_main(t_god *data);
t_render	*init_render(t_god *parse_data);
void		free_game(t_render *game);

void		sl_hooks(void *param);
void		calc_pixels(t_render *game);

/* calc_distnace */
void		calc_distance(t_render *game);
float		get_dist(float ax, float ay, float bx, float by);
void		set_hor_start_values(t_render *game, t_calc *calc);
void		set_vert_start_values(t_render *game, t_calc *calc);

/* utils */
size_t		array_len(char **array);
uint32_t	get_rgb(int a, int r, int g, int b);

#endif