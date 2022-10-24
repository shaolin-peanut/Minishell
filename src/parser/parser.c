/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:10 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 13:34:36 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Reads the line given by readline(), interpret whatever input is given
and creates tokens with all data necessary to understand the token's 
relationships with its neighbors */

void	lexical_scan(char *str, t_meta *pkg)
{
	if (is_word(str, pkg->i))
		process_word(str, pkg);
	else if (is_dollar(str[pkg->i]))
		process_dollar(str, pkg);
	else if (is_operator(str, pkg->i))
		process_operator(str, pkg);
}

int	parser(char *str, t_meta *pkg)
{
	pkg->str = str;
	while (str[pkg->i] != '\0')
	{
		printf("STR[%d]:'%c'\n", pkg->i, str[pkg->i]);
		lexical_scan(str, pkg);
		pkg->i++;
	}
	return (1);
}
