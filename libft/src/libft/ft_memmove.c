/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:34:15 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/12 17:34:19 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	if (!dest && !src)
		return (NULL);
	dst2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (src < dest)
	{
		src2 = src2 + n - 1;
		dst2 = dst2 + n - 1;
		while (n--)
			*(dst2--) = *(src2--);
	}
	else if (src >= dest)
	{
		while (n--)
			*(dst2++) = *(src2++);
	}
	return (dest);
}
