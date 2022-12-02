/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	processing_redirection(t_meta *pkg)
{
	t_token	*token;

	if (have_token_redirection(pkg))
	{
		token = get_first_token_redirection(pkg);
		while (token)
		{
			manage_fd_for_redirection(token);
			token = get_next_token_redirection(token);
		}
	}
}

void	change_fd_cmd(t_token *token, int fd_in, int fd_out)
{
	t_bltn	*bltn;
	t_cmd	*cmd;

	if (token->type == builtin_t)
	{
		bltn = cast_token(token);
		bltn->fd_in = fd_in;
		bltn->fd_out = fd_out;
	}
	else if (token->type == cmd_t)
	{
		cmd = cast_token(token);
		cmd->fd_in = fd_in;
		cmd->fd_out = fd_out;
	}
}

void	redirect_cmd(t_cmd *cmd)
{
	int	fd_in;
	int	fd_out;

	fd_in = cmd->fd_in;
	fd_out = cmd->fd_out;
	if (!is_standard_fd(fd_in))
		dup2(fd_in, STDIN_FILENO);
	if (!is_standard_fd(fd_out))
		dup2(fd_out, STDOUT_FILENO);
}
