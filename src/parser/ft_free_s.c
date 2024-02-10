/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkalika <kkalika@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 14:54:25 by code          #+#    #+#                 */
/*   Updated: 2024/02/10 17:59:22 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
