/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:10 by sbars             #+#    #+#             */
/*   Updated: 2022/09/02 17:42:57 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// In these functions, the printf can easily be replaced by "create_x_token" functions
int		lexical_scan(char	**str, int i)
{
	if (is_word(str, i))
		printf("word found: %s\n", str[i]);
	else if (is_dollar(str[i][0]))
	{
		if (is_var(str, i))
		{
			str[i] = var_substitution(str, i);
			printf("var found: %s\n", str[i]);
		}
	}
	else
		printf("something else found %s\n", str[i]);
	return (1);
}

void	parser(char	*str)
{
	int	i;
	char	**split_str;

	i = -1;
	split_str = ft_split(str, ' ');
	free(str);
	while (split_str[++i] != NULL)
		lexical_scan(split_str, i);
	// chain = tokenizer(split_str);
	// return (chain);
	free(split_str);
}
