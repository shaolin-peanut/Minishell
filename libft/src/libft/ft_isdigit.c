/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                  		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:40:15 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/12 14:40:17 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_isdigit_str(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}
