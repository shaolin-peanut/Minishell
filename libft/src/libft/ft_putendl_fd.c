/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:46:10 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 17:46:12 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	r;

	r = ft_putstr_fd(s, fd);
	r += ft_putchar_fd('\n', fd);
	return (r);
}
