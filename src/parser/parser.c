/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:10 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:22:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// In these functions, the printf can easily be replaced by "create_x_token" functions
int	lexical_scan(char	*str, int i, t_meta	*pkg)
{
	// The only way I can simplify this down to small function, is to have big abstractions that are as big as possible, buckets, that lead to smaller buckets. I try to find similar characteristics, how to group elements in the most efficient way.
	if (is_word(str, i))
		i = process_word(str, i, pkg);
	else if (is_dollar(str[i]))
		i = process_dollar(str, i, pkg);
	else if (is_operator(str, i))
		i = process_operator(str, i, pkg);
	else
		i++;
	return (i);
}

int	parser(char	*str, t_meta	*pkg)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = lexical_scan(str, i, pkg);
		if (i == -1)
		{
			free(str);
			return (0);
		}
		i++;
	}
	// chain = tokenizer(split_str);
	// return (chain);
	free(str);
	return (1);
}
