/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:36 by sbars             #+#    #+#             */
/*   Updated: 2022/11/08 15:56:47 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_word(char *word, t_meta *pkg)
{
	char	*path;

	path = NULL;
	if (!word)
		errormsg("minishell: : command not found\n", pkg);
	if (is_builtin(word, pkg))
	{
		create_builtin_token(word, pkg);
		return ;
	}
	path = is_cmd(word, pkg);
	if (!path)
		create_word_token(word, pkg);
	else if (path)
		create_cmd_token(word, path, pkg);
}

void	process_operator(char *str, t_meta *pkg)
{
	if (is_pipe(str[pkg->i], 0))
		create_operator_token(pkg, TOK_PIPE);
	else if (is_heredoc(str, pkg->i))
		create_operator_token(pkg, TOK_HEREDOC);
	else if (is_redirection(str, pkg->i))
		create_operator_token(pkg, is_redirection(str, pkg->i));
}

void	process_dollar(char *str, t_meta *pkg)
{
	printf("> dollar: %s\n", str + pkg->i);
	if (is_var(str, pkg->i))
		process_variable(pkg, pkg->str, pkg->i);
	if (is_dollar_question(str, pkg->i))
		(void) pkg;
	// just_print_last_fd_exit_status;
	else
		(void) pkg;
}
