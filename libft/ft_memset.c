/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:19 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:01:01 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long int	i;
	char				*str;

	str = (char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b = str);
}
