/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 00:14:49 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/21 00:14:51 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_number_of_splits(char *str, char c);
static void		ft_split_cpy(char *str, char c, char **tab);
static char		*ft_make_cpy(char *src, unsigned int n);

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		nb;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	nb = ft_number_of_splits(str, c);
	tab = malloc(sizeof (char *) * (nb + 1));
	if (! tab)
		return (NULL);
	ft_split_cpy(str, c, tab);
	return (tab);
}

void	ft_split_cpy(char *str, char c, char **tab)
{
	int		count;
	int		end;
	bool	valid;

	count = 0;
	end = -1;
	valid = 0;
	while (str[++end] != '\0')
	{
		if (str[end] == c && valid)
		{
			valid = false;
			tab[count++] = ft_make_cpy(str, end);
		}
		else if (str[end] != c && !valid)
		{
			str = str + end;
			end = 0;
			valid = true;
		}
	}
	if (valid)
		tab[count++] = ft_make_cpy(str, end);
	tab[count] = 0;
}

int	ft_number_of_splits(char *str, char c)
{
	int		count;
	bool	valid;

	count = 0;
	valid = 0;
	if (!c)
		return (0);
	while (*str != '\0')
	{
		if (*str == c && valid)
		{
			valid = false;
			++count;
		}
		else if (*str != c && !valid)
			valid = true;
		++str;
	}
	if (valid)
		++count;
	return (count);
}

char	*ft_make_cpy(char *src, unsigned int n)
{
	unsigned int	i;
	char			*dest;

	dest = malloc(sizeof (char) * (n + 1));
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
