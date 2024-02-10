/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkalika <kkalika@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/08 21:21:33 by kkalika       #+#    #+#                 */
/*   Updated: 2024/02/10 18:11:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*freegnl(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*strljoin(char *s1, char *s2, int length, int x)
{
	char	*nstr;
	int		i;
	int		s;

	s = 0;
	i = lookend(s1);
	nstr = ft_calloc((i + length + 1), sizeof(char));
	if (!nstr)
		return (NULL);
	while (s1 && s1[x] != '\0')
	{
		nstr[x] = s1[x];
		x++;
	}
	while (s2 && s < length)
	{
		nstr[x] = s2[s];
		x++;
		s++;
	}
	if (s1)
		s1 = freegnl(s1);
	return (nstr);
}

int	nl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	lookend(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}
