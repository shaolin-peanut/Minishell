/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:18:19 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 12:18:20 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (! s1 || ! set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + begin)))
		begin++;
	while (ft_strchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
}
