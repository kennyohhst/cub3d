/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:04:30 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:59:18 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;
	size_t			x;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	i = 0;
	x = 0;
	while (i < n)
	{
		if (one[i] != two[i])
			return (x = (one[i] - two[i]));
		i++;
	}
	return (0);
}
