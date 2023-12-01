/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:06:52 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:02:20 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	t_len;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *) malloc(t_len + 1);
	if (nstr == NULL)
		return (nstr);
	while (*s1 != '\0')
	{
		*nstr = *(char *) s1;
		s1++;
		nstr++;
	}
	while (*s2 != '\0')
	{
		*nstr = *(char *) s2;
		s2++;
		nstr++;
	}
	*nstr = '\0';
	return (nstr - t_len);
}
