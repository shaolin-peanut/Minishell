/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:57:09 by sbars             #+#    #+#             */
/*   Updated: 2022/11/02 17:55:17 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_operator(char *str, int i)
{
	if (is_pipe(str[i], 0) || is_redirection(str, i) || is_heredoc(str, i))
		return (true);
	return (false);
}

int	is_redirection(char *str, int i)
{
	if (str[i] == '<')
		return (TOK_REDIR_IN);
	else if (str[i] == '>')
		return (TOK_REDIR_OUT);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (TOK_APPEND_OUT);
	return (false);
}

bool	is_heredoc(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (true);
	return (false);
}

bool is_pipe(char c, int i)
{
	i++;
	if (c == '|')
		return (true);
	return (false);
}
