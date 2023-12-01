/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:59:29 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:58:38 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	char				*iampointerstring;

	iampointerstring = (char *) s;
	i = 0;
	while (i < n)
	{
		iampointerstring[i] = '\0';
		i++;
	}
}
