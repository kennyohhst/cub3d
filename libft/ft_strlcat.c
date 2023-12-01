/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:06:56 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:02:43 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest;
	size_t	i;
	size_t	y;

	i = 0;
	dest = ft_strlen(dst);
	y = dest;
	if (dstsize == 0 || dest >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] != 0 && y < (dstsize - 1))
	{
		dst[y] = src[i];
		y++;
		i++;
	}
	dst[y] = '\0';
	return ((dest + ft_strlen(src)));
}
