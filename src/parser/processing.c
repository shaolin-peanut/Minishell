/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:36 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 15:18:59 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include "../../include/minishell.h"

bool	process_word(char *word, t_meta *pkg)
{
	char	*path;

	path = NULL;
	if (is_builtin(word, pkg))
		return (create_builtin_token(word, pkg));
	else
	{
		path = is_cmd(word, pkg);
		create_cmd_token(word, path, pkg);
	}
	return (true);
}

bool	process_operator(char *str, t_meta *pkg)
{
	if (is_pipe(str[pkg->i]))
		create_operator_token(pkg, pipe_t);
	else if (is_heredoc(str, pkg->i))
		return (create_operator_token(pkg, heredoc));
	else if (is_redirection(str, pkg->i))
		return (create_operator_token(pkg, is_redirection(str, pkg->i)));
	return (true);
}

void	print_cmd_not_found(char *str)
{
	perror(str);
}
//	ft_putstr_fd("minishell: ", STDERR_FILENO);
//	ft_putstr_fd(str, STDERR_FILENO);
//	ft_putstr_fd(": Command not found\n", STDERR_FILENO);
//	perror("minishell: ");
//	strerror(ENOENT);
