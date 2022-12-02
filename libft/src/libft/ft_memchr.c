/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:08:09 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/12 19:08:11 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*big;
	size_t		i;

	big = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (big[i] == (char)c)
			return ((void *)&big[i]);
		++i;
	}
	return (NULL);
}
