/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:05:05 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:00:30 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	dest = (char *) dst;
	source = (char *) src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (source > dest)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	while (i < len)
	{
		dest[len - 1] = source[len - 1];
		len--;
	}
	return (dst = dest);
}
