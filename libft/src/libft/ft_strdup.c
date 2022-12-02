/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:46:23 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/13 17:46:25 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	ptr_size;
	char	*ptr;

	if (!str)
		return (NULL);
	ptr_size = ft_strlen(str) + 1;
	ptr = malloc(ptr_size);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, ptr_size);
	return (ptr);
}
