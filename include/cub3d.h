/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: code <code@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 16:01:38 by code          #+#    #+#                 */
/*   Updated: 2024/02/10 17:58:52 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../lib/mlx42/include/MLX42/MLX42.h"
# include "game_settings.h"
# include "structs.h"

#define PIXEL 64
#define PI 3.14159265358979323846
#define PI2 PI/2
#define PI3 3*PI/2

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

/* render functions */
void		render_main(t_god *data);
t_render	*init_render(void);

void	sl_hooks(void *param);
void	calc_pixels(t_render *game);

/* calc_distnace */
void	calc_distance(t_render *game);
float	get_dist(float ax, float ay, float bx, float by);
void	set_hor_start_values(t_render *game, t_calc *calc);
void	set_vert_start_values(t_render *game, t_calc *calc);

/* utils */
size_t	array_len(char **array);
uint32_t get_RGB(int a, int r, int g, int b);

#endif