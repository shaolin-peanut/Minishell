/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:02:36 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 19:49:48 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_write(char *str, int n, size_t size)
{
	int	i;

	i = size;
	if (n == -2147483648)
		ft_strcpy(str, "-2147483648");
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[size + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		nb;

	nb = n;
	size = ft_len(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	return (ft_write(str, nb, size));
}
