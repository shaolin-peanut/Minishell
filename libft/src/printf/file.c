/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:41:38 by gmontaur          #+#    #+#             */
/*   Updated: 2021/11/02 09:41:42 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	absolute_value(int nbr);
static int	get_len_base(unsigned long nbr, int base);

int	ft_putnbr(long n)
{
	char	c;
	int		i;

	i = 0;
	if (n == LONG_MIN)
		return (write(STDOUT_FILENO, "-9223372036854775808", 20));
	if (n < 0)
	{
		n *= -1;
		i += write(STDOUT_FILENO, "-", 1);
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		c = '0' + n;
		i += write(STDOUT_FILENO, &c, 1);
	}
	return (i);
}

int	ft_putstr(char *str)
{
	size_t	res;

	if (str)
	{
		res = write(STDOUT_FILENO, str, ft_strlen(str));
		free(str);
		return (res);
	}
	res = write(STDOUT_FILENO, "(null)", ft_strlen("(null)"));
	return (res);
}

char	*ft_itoa_base(unsigned long n, int base)
{
	char	*str;
	int		len;
	int		r;

	len = get_len_base(n, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		*str = '0';
	while (n != 0)
	{
		--len;
		r = absolute_value(n % base);
		if (r > 9)
			str[len] = r - 10 + 'a';
		else
			str[len] = r + '0';
		n /= base;
	}
	return (str);
}

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	get_len_base(unsigned long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr /= base;
	}
	return (len);
}
