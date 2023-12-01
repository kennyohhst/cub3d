/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:02:36 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:59:10 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long int x)
{
	int	count;

	if (x > 0)
		count = 0;
	if (x <= 0)
		count = 1;
	while (x != 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int c)
{
	long int	tempnb;
	int			x;
	char		*number;

	tempnb = (long) c;
	x = ft_countdigits(tempnb) - 1;
	number = (char *) malloc(ft_countdigits(tempnb) + 1);
	if (!number)
		return (NULL);
	number[ft_countdigits(c)] = '\0';
	if (tempnb < 0)
	{
		number[0] = '-';
		tempnb = tempnb * -1;
	}
	if (tempnb == 0)
		number[x] = '0';
	while (tempnb != 0 && x >= 0)
	{
		number[x] = (char)(tempnb % 10) + '0';
		tempnb = tempnb / 10;
		x--;
	}
	return (number);
}
