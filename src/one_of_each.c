/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_of_each.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:16:27 by code              #+#    #+#             */
/*   Updated: 2023/12/06 13:27:46 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	one_of_each(char **full_map, char *c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (full_map[i])
	{
		if (!ft_memcmp(c, full_map[i], 2))
			x++;
		if (x > 1)
		{
			write(2, c, ft_strlen(c));
			write(2, "\n", 1);
			write(2, "Error\none_of_each_1\n", 20);
			exit(2);
		}
		i++;
	}
}