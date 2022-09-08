/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:10 by sbars             #+#    #+#             */
/*   Updated: 2022/09/08 17:00:12 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// In these functions, the printf can easily be replaced by "create_x_token" functions
int	lexical_scan(char	**str, int i, t_meta	*pkg)
{
	if (is_word(str, i))
	{
		printf("word found: %s\n", str[i]);
		if (!is_cmd(str, i) && !is_builtin(str, i))
			return (errormsg("Command not found", pkg));
	}
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

int	parser(char	*str, t_meta	*pkg)
{
	int	i;
	char	**split_str;

	i = -1;
	split_str = ft_split(str, ' ');
	free(str);
	while (split_str[++i] != NULL)
	{
		if (!lexical_scan(split_str, i, pkg))
		{
			free(split_str);
			return (0);
		}
	}
	// chain = tokenizer(split_str);
	// return (chain);
	free(split_str);
	return (1);
}
