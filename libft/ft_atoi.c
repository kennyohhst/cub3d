/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:58:58 by kkalika           #+#    #+#             */
/*   Updated: 2022/12/27 14:58:30 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign_neg(char sign)
{
	if (sign == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		x;
	int		neg;

	s = (char *) str;
	i = 0;
	x = 0;
	neg = 1;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] && (s[i] == 43 || s[i] == 45))
	{
		neg = is_sign_neg(s[i]);
		i++;
	}
	while (s[i] && s[i] >= 48 && s[i] <= 57)
	{
		x = (x * 10) + (s[i] - 48);
		i++;
	}
	return (x * neg);
}
