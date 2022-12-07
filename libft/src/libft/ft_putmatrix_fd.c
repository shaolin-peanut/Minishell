/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:57:39 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/20 17:57:39 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putmatrix_fd(char **m, int nl, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (m && m[i])
	{
		if (nl)
			count += ft_putendl_fd(m[i], fd);
		else
			count += ft_putstr_fd(m[i], fd);
		i++;
	}
	return (count);
}

int ft_putstr_until(char *str, char c, int fd)
{
	char	*this;
	int 	i;

	this = str;
	i = 0;
	while (*this && *this != c)
	{
		i += write(fd, this, 1);
		++this;
	}
	return (i);
}

int	ft_putmatrix_fd_export(char **m, int fd)
{
	int		i;
	int		count;
	int 	j;
	char	*val;

	count = 0;
	i = 0;
	while (m && m[i])
	{
		count += ft_putstr_fd("declare -x ", fd);
		j = ft_putstr_until(m[i], '=', fd);
		count += j;
		val = m[i] + j;
		if (*val && *val == '=')
		{
			count += ft_putchar_fd('=', fd);
			++val;
			count += ft_putchar_fd('\"', fd);
			count += ft_putstr_fd(val, fd);
			count += ft_putchar_fd('\"', fd);
		}
		count += ft_putchar_fd('\n', fd);
		i++;
	}
	return (count);
}
