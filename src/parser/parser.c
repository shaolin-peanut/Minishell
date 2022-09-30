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

#include "../../include/minishell.h"

/* reads the command line such as “ls ­al”
puts it into a data structure called Command Table
that will store the commands that will be executed.*/

int lexical_scan(char *str, t_meta *pkg)
{
	if (is_word(str, pkg->i))
		pkg->i = process_word(str, pkg);
	// TODO: debug and finish writing all the functions commented out below.
	// else if (is_dollar(str[i]))
	//	i = process_dollar(str, i, pkg);
	else if (is_operator(str, pkg->i))
		pkg->i = process_operator(str, pkg);
	return (pkg->i);
}

int parser(char *str, t_meta *pkg)
{
	while (str[pkg->i] != '\0')
	{
		printf("STR[%d]:'%c'======\n", pkg->i, str[pkg->i]);
		pkg->i = lexical_scan(str, pkg);
		// TODO: Figure out if you need the unused error management thing below. If not, delete.
		/*if (i == -1)
		{
			free(str);
			return (0);
		}*/
		pkg->i++;
	}
	// chain = tokenizer(str);
	// return (chain);
	free(str);
	return (1);
}
