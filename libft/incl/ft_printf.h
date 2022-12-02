/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:40:51 by gmontaur          #+#    #+#             */
/*   Updated: 2021/11/02 10:40:53 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# define CHAR 'c'
# define STRING 's'
# define POINTER 'p'
# define DECIMAL 'd'
# define INTEGER 'i'
# define UINTEGER 'u'
# define HEXALOW 'x'
# define HEXAUP 'X'
# define PERCENT '%'

int		ft_printf(const char *format, ...);

int		ft_putchar(char c);

int		ft_putnbr(long n);

int		ft_putstr(char *str);

char	*ft_itoa_base(unsigned long n, int base);

char	*ft_ptr_format(char *str);

char	*ft_str_toupper(char *str);
#endif //FT_PRINTF_H
