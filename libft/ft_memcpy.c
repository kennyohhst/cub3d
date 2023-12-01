/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:04:49 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:59:47 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char *) dst;
	source = (char *) src;
	i = 0;
	if (source != NULL || dest != NULL)
	{
		if (n != 0)
		{	
			while (n != i)
			{
				dest[i] = source[i];
				i++;
			}
		}
	}
	return (dst);
}
