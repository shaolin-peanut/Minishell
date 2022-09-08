/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_A.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/09/02 17:14:13 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_dollar(char c)
{
	if (c == '$')
		return (1);
	else
		return (0);
}	

int	is_squote(char c)
{
	if (c == 39)
		return (1);
	return (0);
}

int	is_dquote(char	c)
{
	if (c == 34)
		return (1);
	return (0);
}

int	is_var(char	**str, int i)
{
	int	j;

	j = 0;
	if (!ft_isalnum(str[i][++j]))
		return (0);
	while (ft_isalnum(str[i][++j]))
		;
	return (j);
}

int	is_word(char	**str, int i)
{
	int	j;

	j = -1;
	if (str[i] == NULL)
		return (0);
	while (str[i][++j])
	{
		if (!ft_isalnum(str[i][j]))
			return (0);
	}
	return (j);
}
