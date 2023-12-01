/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:07:31 by kkalika           #+#    #+#             */
/*   Updated: 2023/10/20 20:32:26 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*trim;
	size_t	i;

	if (!s1 || !set)
		return (0);
	str = (char *) s1;
	trim = (char *) set;
	while (ft_strchr(trim, *str) && *str)
		str++;
	i = ft_strlen(str);
	while (ft_strchr(trim, str[i]) && i != 0)
		i--;
	return (ft_substr(str, 0, i + 1));
}
