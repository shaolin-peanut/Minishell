/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:09:30 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/13 11:18:50 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;

	i = 0;
	hay = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || little == big)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] != '\0' && little[c] != '\0'
			&& hay[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (hay + i);
		++i;
	}
	return (0);
}
