/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:09:07 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 18:12:22 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[10];
	char	src[10] = "hello";
	int	i;
	int	j;

	i = strlcpy(dest, src, 10);
	printf("dest from strcpy is %s and i is %d\n", dest, i);
	j = ft_strlcpy(dest, src, 10);
	printf("dest from ft_strcpy is %s and j is %d\n", dest, j);
	return (0);
}
*/
