/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:12 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:14 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	absolute_value(int nbr);
static int	get_len(int nbr);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		*str = '-';
	else if (n == 0)
		*str = '0';
	while (n != 0)
	{
		--len;
		str[len] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr /= 10;
	}
	return (len);
}
