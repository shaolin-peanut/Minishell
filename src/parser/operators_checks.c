/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:57:09 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 15:09:40 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_operator(char *str, int i)
{
	if (is_pipe(str[i]) || is_redirection(str, i) || is_heredoc(str, i))
		return (true);
	return (false);
}

int	is_redirection(char *str, int i)
{
	if (str[i] == '<')
		return (redir_in);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (append_out);
	else if (str[i] == '>')
		return (redir_out);
	return (false);
}

bool	is_heredoc(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (true);
	return (false);
}

bool	is_pipe(char c)
{
	if (c == '|')
		return (true);
	return (false);
}
