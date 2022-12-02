/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:03:35 by gmontaur          #+#    #+#             */
/*   Updated: 2021/11/02 10:03:37 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_flags(const char *flag, va_list args)
{
	int	i;

	i = 0;
	if (*flag == CHAR)
		i += ft_putchar(va_arg(args, int));
	else if (*flag == DECIMAL || *flag == INTEGER)
		i += ft_putnbr(va_arg(args, int));
	else if (*flag == STRING)
		i += ft_putstr(ft_strdup(va_arg(args, char *)));
	else if (*flag == POINTER)
		i += ft_putstr(ft_ptr_format(ft_itoa_base(va_arg(args,
							unsigned long), 16)));
	else if (*flag == HEXALOW)
		i += ft_putstr(ft_itoa_base(va_arg(args,
						unsigned int), 16));
	else if (*flag == HEXAUP)
		i += ft_putstr(ft_str_toupper(ft_itoa_base(va_arg(args,
							unsigned int), 16)));
	else if (*flag == UINTEGER)
		i += ft_putnbr(va_arg(args, unsigned int));
	else if (*flag == PERCENT)
		i += ft_putchar(PERCENT);
	else
		i += ft_putchar(*flag);
	return (i);
}

int	f(const char *format, va_list args)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			r += ft_flags(&format[i + 1], args);
			++i;
		}
		else
			r += ft_putchar(format[i]);
		++i;
	}
	return (r);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			r;

	r = 0;
	va_start(args, format);
	r += f(format, args);
	va_end(args);
	return (r);
}
