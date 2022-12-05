/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:03:17 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;
	t_cmd	*cmd;

	cmd = NULL;
	tok = NULL;
	tok = init_token(pkg);
	tok->type = cmd_t;
	tok->token = init_cmd(pkg);
	cmd = cast_token(tok);
	cmd->binary_path = full_path;
	cmd->argv = build_argument_vector(cmd_name, pkg);
	cmd->argc = ft_matrixlen(cmd->argv);
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->pid = 0;
	return (true);
}

bool	create_builtin_token(char *name, t_meta	*pkg)
{
	t_token		*tok;
	t_bltn		*builtin;

	tok = NULL;
	builtin = NULL;
	tok = init_token(pkg);
	tok->type = builtin_t;
	tok->token = init_builtin(pkg);
	builtin = cast_token(tok);
	builtin->argv = build_argument_vector(name, pkg);
	builtin->argc = ft_matrixlen(builtin->argv);
	builtin->fd_in = STDIN_FILENO;
	builtin->fd_out = STDOUT_FILENO;
	builtin->pid = 0;
	return (true);
}

bool	create_operator_token(t_meta *pkg, int type)
{
	t_token	*tok;
	t_op	*op;

	tok = NULL;
	op = NULL;
	tok = init_token(pkg);
	tok->type = op_t;
	tok->token = init_op(pkg);
	op = cast_token(tok);
	op->type = type;
	op->fd_in = STDIN_FILENO;
	op->fd_out = STDOUT_FILENO;
	if (type == heredoc)
		return (capture_heredoc(pkg));
	else if (is_redirection(pkg->str, pkg->i))
		return (file_check_and_create(pkg, type));
	else
		return (true);
}

bool	create_file_token(char *str, t_meta *pkg, int type)
{
	t_token	*tok;
	t_file	*file;

	tok = NULL;
	file = NULL;
	tok = init_token(pkg);
	tok->type = file_t;
	tok->token = init_file(pkg);
	file = cast_token(tok);
	if (type == heredoc)
	{
		file->name = "tmp.txt";
		file->fd = open("tmp.txt", O_CREAT | O_WRONLY, 0777);
		write(file->fd, str, ft_strlen(str));
		close(file->fd);
		free(str);
	}
	else
	{
		file->name = str;
		file->fd = 0;
	}
	return (true);
}
