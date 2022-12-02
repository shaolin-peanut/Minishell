/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:14:45 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/20 18:14:47 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*ptr;

	size = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	*ptr = 0;
	if (s1)
		ft_strlcat(ptr, s1, (ft_strlen(s1) + 1));
	if (s2)
		ft_strlcat(ptr, s2, (size + 1));
	return (ptr);
}
