/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:07:27 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:03:42 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		slen;
	char	*str;

	str = (char *) s;
	slen = ft_strlen(str);
	while (slen >= 0)
	{
		if (str[slen] == (char) c)
			return (&str[slen]);
		slen--;
	}
	return (0);
}
