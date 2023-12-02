/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:13 by kkalika           #+#    #+#             */
/*   Updated: 2023/12/02 14:11:17 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*killall(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (NULL);
}

int	read_line(char **tline, char **dst, int fd)
{
	if (*tline == NULL)
		return (0);
	*dst = strljoin(*dst, *tline, lookend(*tline), 0);
	if (*dst == NULL)
		return (0);
	*tline = freegnl(*tline);
	*tline = ft_calloc((BUFFERSIZE + 1), sizeof(char));
	if (*tline == NULL)
		return (freegnl(*dst), 0);
	return (read(fd, *tline, BUFFERSIZE));
}

void	return_line(char **dst, char **tl, char **b)
{
	if (!*tl)
		return ;
	*dst = strljoin(*dst, *tl, (nl(*tl) + 1), 0);
	*b = strljoin(*b, *tl + (nl(*tl) + 1), lookend(*tl) - (nl(*tl) + 1), 0);
}

char	*two_callocs(char **tmp, char **dest)
{
	*tmp = ft_calloc((BUFFERSIZE + 1), sizeof(char));
	if (!*tmp)
		return (NULL);
	*dest = ft_calloc((BUFFERSIZE + 1), sizeof(char));
	if (!*dest)
		return (freegnl(*tmp));
	return (*tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	char		*dest;
	int			i;

	if (fd < 0 || fd > 1024 || read(fd, buff, 0) == -1)
		return (NULL);
	if (two_callocs(&tmp, &dest) == NULL)
		return (NULL);
	if (buff)
		tmp = strljoin(tmp, buff, lookend(buff), 0);
	if (buff)
		buff = freegnl(buff);
	while (nl(tmp) == -1)
	{
		i = read_line(&tmp, &dest, fd);
		if ((dest == NULL || dest[0] == '\0') && i == 0)
			return (killall(tmp, buff, dest));
		if (i == 0)
			break ;
	}
	return_line(&dest, &tmp, &buff);
	return (freegnl(tmp), dest);
}
