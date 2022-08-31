/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/08/30 17:44:36 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*int	is_squote(char	*str, int i)
{
	if (str[i] == 39)
		return (1);
	return (0);
}

int	is_dquote(char	*str, int i)
{
	if (str[i] == 34)
		return (1);
	return (0);
}

int	is_dollar_sign(char	*str, int i)
{
	if (str[i] == '$')
		return (1);
	else
		return (0);
}*/

int	var_substitution(char *str, int i)
{
	int	before;

	before = i;
	printf("variable found ");
	while (ft_isalnum(str[i]) && str[i] != '\0')
		i++;
	printf("Variable found %s\n", ft_substr(str, before, i - before));
	return (i);
}

int	word_extraction(char *str, int i)
{
	int	before;
/*	if (ft_isalnum(str[i]))
	{
		while (!is_space_tab(str, i) && ft_isalnum(str[i]) && str[i] != '\0')
		{
			if (is_space_tab(str, i))
				break;
			i++;
		}
	}*/

	before = i;
	while (ft_isalnum(str[i]) && str[i] != '\0')
		i++;
	printf("Word found %s\n", ft_substr(str, before, i - before));
	return (i);
}
