/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 13:21:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/12/30 17:43:42 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define PIXEL 64
#define PI 3.1415926535
#define FOV 1.2
#define ROTATE 0.1
#define MS 0.2
#define WIDTH 4000
#define HEIGHT 2000
#define BPP sizeof(int32_t)

void	sl_hooks(mlx_key_data_t keydata, void *param);
