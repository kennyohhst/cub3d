/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:07:45 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 15:04:09 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rstr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!s)
		return (NULL);
	rstr = (char *) malloc(len + 1);
	if (!rstr)
		return (NULL);
	ft_strlcpy(rstr, s + start, len + 1);
	return (rstr);
}
