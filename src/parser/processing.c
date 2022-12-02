/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:36 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:06:16 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	process_word(char *word, t_meta *pkg)
{
	char	*path;

	path = NULL;
	if (!word)
		errormsg("minishell: : command not found\n", pkg);
	if (is_builtin(word, pkg))
	{
		create_builtin_token(word, pkg);
		return (true);
	}
	path = is_cmd(word, pkg);
	if (!path)
		create_word_token(word, pkg);
	else
		create_cmd_token(word, path, pkg);
	return (true);
}

bool	process_operator(char *str, t_meta *pkg)
{
	int	type;

	type = 0;
	if (is_pipe(str[pkg->i]))
		create_operator_token(pkg, pipe_t);
	else if (is_heredoc(str, pkg->i))
		return (create_operator_token(pkg, heredoc));
	else if (is_redirection(str, pkg->i))
	{
		type = is_redirection(str, pkg->i);
		create_operator_token(pkg, type);
		return (file_check_and_create(pkg, type));
	}
	return (true);
}

bool	process_dollar(char *str, t_meta *pkg)
{
	if (is_var(str, pkg->i))
		process_variable(pkg, pkg->str, pkg->i);
	return (true);
}
