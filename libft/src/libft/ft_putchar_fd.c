/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:36:12 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 17:36:14 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	r;

	r = write(fd, &c, sizeof(char));
	if (r < 0)
		return (r);
	return (-1);
}
