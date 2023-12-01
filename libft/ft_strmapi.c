/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:53 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:03:06 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	i = 0;
	nstr = (char *) malloc(ft_strlen(s) + 1);
	if (!nstr)
		return (NULL);
	while (s[i] != '\0')
	{
		nstr[i] = (*f)(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
