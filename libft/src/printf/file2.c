/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:41:38 by gmontaur          #+#    #+#             */
/*   Updated: 2021/11/02 09:41:42 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

int	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

char	*ft_ptr_format(char *str)
{
	char	*res;

	res = ft_strjoin("0x", str);
	free(str);
	return (res);
}

char	*ft_str_toupper(char *str)
{
	char	*res;

	res = str;
	while (*str)
	{
		*str = ft_toupper((int)*str);
		++str;
	}
	return (res);
}
