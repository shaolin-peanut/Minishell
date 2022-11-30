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

bool	lexical_scan(char *str, t_meta *pkg)
{
	char	*word;

	word = NULL;
	if (is_word(str, pkg->i))
	{
		word = return_word(str, pkg);
		//printf("%s\n", word);
		return (process_word(word, pkg));
	}
	else if (is_dollar(str[pkg->i]))
		return (process_dollar(str, pkg));
	else if (is_operator(str, pkg->i))
		return (process_operator(str, pkg));
	return (true);
}

bool	parser(char *str, t_meta *pkg)
{
	bool	ret;

	pkg->str = NULL;
	pkg->i = 0;
	ret = true;
	pkg->str = str;
	while (str[pkg->i] != '\0')
	{
		ret = lexical_scan(str, pkg);
		if (!ret)
			break ;
		pkg->i++;
		if ((int) ft_strlen(str) < pkg->i)
			break ;
	}
	return (ret);
}
		// printf("STR[%d]:'%c'\n", pkg->i, str[pkg->i]);
