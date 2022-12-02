/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	manage_fd_for_redirection(t_token *token)
{
	t_op	*this;

	this = cast_token(token);
	if (is_token_basic_redirection(this))
		manage_fd_basic_redirection(token);
	else if (this->type == pipe_t)
		manage_fd_pipe(token);
}

void	manage_fd_pipe(t_token *token)
{
	t_token	*prev_cmd;
	t_token	*next_cmd;
	t_op	*pipe_tok;
	int		fd[2];

	prev_cmd = get_prev_token_cmd(token);
	next_cmd = get_next_token_cmd(token);
	if (!next_cmd || !prev_cmd)
		return ;
	pipe(fd);
	change_fd_cmd(prev_cmd, get_fd_in(prev_cmd), fd[1]);
	change_fd_cmd(next_cmd, fd[0], get_fd_out(next_cmd));
	pipe_tok = cast_token(token);
	pipe_tok->fd_in = fd[1];
	pipe_tok->fd_out = fd[0];
}

void	manage_fd_basic_redirection(t_token *token)
{
	t_token	*prev_token;
	t_op	*op;
	t_file	*next_file;

	prev_token = get_prev_token_cmd(token);
	next_file = get_next_token_file(token);
	if (!prev_token || !next_file)
		return ;
	op = cast_token(token);
	if (op->type == redir_in || op->type == heredoc)
	{
		open_next_file_with_flags(op->type, next_file);
		change_fd_cmd(prev_token, next_file->fd, get_fd_out(prev_token));
	}
	else if (op->type == redir_out || op->type == append_out)
	{
		open_next_file_with_flags(op->type, next_file);
		change_fd_cmd(prev_token, get_fd_in(prev_token), next_file->fd);
	}
}

void	open_next_file_with_flags(int type, t_file *file)
{
	if (type == redir_in || type == heredoc)
		file->fd = open(file->name, O_RDONLY);
	else if (type == redir_out)
		file->fd = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == append_out)
		file->fd = open(file->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
}
