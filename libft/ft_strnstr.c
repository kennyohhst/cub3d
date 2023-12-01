/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:07:18 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:03:22 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	i;
	size_t	c;

	h = (char *) haystack;
	i = 0;
	if (*needle == '\0')
		return (h);
	while (h[i] != '\0' && i < len)
	{
		c = 0;
		while (h[i + c] == needle[c] && i + c < len)
		{
			c++;
			if (needle[c] == '\0')
				return (h + i);
		}
		c = 0;
		i++;
	}
	return (0);
}
