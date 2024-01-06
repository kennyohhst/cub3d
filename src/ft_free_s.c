/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:54:25 by code              #+#    #+#             */
/*   Updated: 2024/01/05 19:09:06 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_s(char **string)
{
	int	i;

	i = 0;
	if (!(*string))
		return ;
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free(string);
}
