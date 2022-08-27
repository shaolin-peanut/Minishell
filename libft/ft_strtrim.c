/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:10:01 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 18:10:59 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < size && ft_strchr(set, s1[size]))
		size--;
	str = ft_substr(s1, i, size - i + 1);
	return (str);
}
