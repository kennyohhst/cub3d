/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:02:52 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:59:14 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ss;
	size_t	i;

	i = 0;
	ss = (char *) s;
	while (i < n)
	{
		if (ss[i] == (char) c)
			return (&ss[i]);
		i++;
	}
	return (0);
}
