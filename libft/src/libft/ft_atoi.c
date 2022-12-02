/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	char	*str;
	short	sign;
	long	res;

	str = (char *)s;
	res = 0;
	sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{
		res *= 10;
		res += (*str - '0');
		++str;
	}
	return (res * sign);
}
