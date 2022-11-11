/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:10 by sbars             #+#    #+#             */
/*   Updated: 2022/11/08 15:53:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Reads the line given by readline(), interpret whatever input is given
and creates tokens with all data necessary to understand the token's 
relationships with its neighbors */

void	lexical_scan(char *str, t_meta *pkg)
{
	char	*word;

	word = NULL;
	if (is_word(str, pkg->i))
	{
		word = return_word(str, pkg);
		process_word(word, pkg);
	}
	else if (is_dollar(str[pkg->i]))
		process_dollar(str, pkg);
	else if (is_operator(str, pkg->i))
		process_operator(str, pkg);
}

t_token	*parser(char *str, t_meta *pkg)
{
	pkg->str = str;
	while (str[pkg->i] != '\0')
	{
		lexical_scan(str, pkg);
		pkg->i++;
	}
	return (NULL);
}
		// printf("STR[%d]:'%c'\n", pkg->i, str[pkg->i]);
