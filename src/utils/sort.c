/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int		ft_strcmp(char *s1, char *s2);
int		find_min(char **tab, int a, int b);
void	swap(char **tab, int a, int b);

void	sort(char **tab)
{
	int	i;
	int	tab_size;
	int	min_i;

	tab_size = ft_matrixlen(tab);
	i = 0;
	while (i < tab_size)
	{
		min_i = find_min(tab, i, tab_size - 1);
		if (i != min_i)
			swap(tab, i, min_i);
		++i;
	}
}

void	swap(char **tab, int a, int b)
{
	char	*tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

int	find_min(char **tab, int a, int b)
{
	int	i;
	int	min_i;
	int	res;

	min_i = a;
	i = a + 1;
	while (i <= b)
	{
		res = ft_strcmp(tab[min_i], tab[i]);
		if (res > 0)
		{
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
