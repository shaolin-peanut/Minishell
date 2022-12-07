/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_char_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 15:48:02 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_word(char	*str, int i)
{
	return (str[i] != '\0' && !is_blank(str, i)
		&& !is_operator(str, i) && !is_dollar(str[i]));
}

bool	is_var(char	*str, int i)
{
	if (i > 0)
		if (is_dollar(str[i - 1]) && is_word(str, i))
			i--;
	return (is_dollar(str[i]) && is_word(str, i + 1));
}

bool	file_check_and_create(t_meta *pkg, int type)
{
	char	*word;

	word = NULL;
	if (type == append_out)
		pkg->i++;
	while (pkg->str[pkg->i] && !word)
	{
		pkg->i++;
		if (is_word(pkg->str, pkg->i))
			word = return_word(pkg->str, pkg);
	}
	if (word && ((type == redir_in && access(word, R_OK) == 0)
			|| type == redir_out || (type == append_out)))
		create_file_token(word, pkg, type);
	else
	{
		perror(word);
		while (pkg->str[pkg->i])
			pkg->i++;
		return (false);
	}
	return (true);
}
