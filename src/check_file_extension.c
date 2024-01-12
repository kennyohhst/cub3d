/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:03:01 by code              #+#    #+#             */
/*   Updated: 2024/01/10 17:26:52 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	dp_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i-1);
}

void	check_file_extension(char *str)
{
	char	check[5];
	ft_strlcpy(check, str + ft_strlen(str) - 4, 5);
	if (!ft_strncmp(check, ".cub", 5))
		return ;
	else
	{
		write(2, "check file name\n", 17);
		exit(2);
	}
}
