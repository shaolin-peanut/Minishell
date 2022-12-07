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

bool	lexical_scan(char *str, t_meta *pkg)
{
	char	*word;

	word = NULL;
	if (is_word(str, pkg->i))
	{
		word = return_word(str, pkg);
		return (process_word(word, pkg));
	}
	else if (is_var(str, pkg->i))
		process_variable(pkg, str, pkg->i);
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
		if (ret == false)
			break ;
		pkg->i++;
		if ((int) ft_strlen(str) < pkg->i)
			break ;
	}
	free(pkg->str);
	pkg->str = NULL;
	return (ret);
}
