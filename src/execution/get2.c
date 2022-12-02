/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_file	*get_next_token_file(t_token *token)
{
	while (token)
	{
		if (token->type == file_t)
			return ((t_file *)(token->token));
		token = token->next;
	}
	return (NULL);
}

int	get_fd_in(t_token *this)
{
	t_bltn	*bltn;
	t_cmd	*cmd;

	if (this->type == builtin_t)
	{
		bltn = cast_token(this);
		return (bltn->fd_in);
	}
	else if (this->type == cmd_t)
	{
		cmd = cast_token(this);
		return (cmd->fd_in);
	}
	return (-42);
}

int	get_fd_out(t_token *this)
{
	t_bltn	*bltn;
	t_cmd	*cmd;

	if (this->type == builtin_t)
	{
		bltn = cast_token(this);
		return (bltn->fd_out);
	}
	else if (this->type == cmd_t)
	{
		cmd = cast_token(this);
		return (cmd->fd_out);
	}
	return (-42);
}

char	*get_current_path(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		perror("getcwd() Error\n");
	return (path);
}

t_file	*get_heredoc_file(t_meta *pkg)
{
	t_token	*tok;
	t_op	*op;
	t_file	*ret;

	tok = NULL;
	tok = get_first_token_redirection(pkg);
	if (!tok)
		return (NULL);
	op = cast_token(tok);
	ret = NULL;
	while (ret == NULL)
	{
		if (op->type == heredoc)
			ret = get_next_token_file(tok);
		else
		{
			tok = get_next_token_redirection(tok);
			if (!tok)
				break ;
			op = cast_token(tok);
			if (!op)
				break ;
		}
	}
	return (ret);
}
