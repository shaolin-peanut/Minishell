/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:07:51 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 18:13:49 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			wordcount++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (wordcount);
}

static int	ft_size(char *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static void	*ft_free(char **array, int i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**result;
	int		wordcount;

	i = 0;
	if (!s)
		return (NULL);
	wordcount = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (NULL);
	while (i < wordcount)
	{
		while (*s == c && *s)
			s++;
		result[i] = ft_substr((char *)s, 0, ft_size((char *)s, c));
		if (!result[i])
			ft_free(result, i);
		s = s + ft_size((char *)s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
