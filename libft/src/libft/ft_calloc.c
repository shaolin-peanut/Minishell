/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:24:46 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/13 17:24:48 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	ptr_size;

	ptr = NULL;
	ptr_size = size * nmemb;
	ptr = malloc(ptr_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, ptr_size);
	return (ptr);
}
