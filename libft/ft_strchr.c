/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:08:06 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 21:42:49 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*a;
	char	*b;
	char	s[] = "abbbc";

	a = strchr(s, 98);
	b = ft_strchr(s, 98);
	
	printf("%s, %s", a, b);
}*/
