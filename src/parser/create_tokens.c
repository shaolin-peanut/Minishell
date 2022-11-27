/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 15:20:17 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;
	t_cmd   *cmd;

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
	return (0);
}

int	create_builtin_token(char *name, t_meta	*pkg)
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
	return (1);
}

int	create_word_token(char *str, t_meta *pkg)
{
	t_token	*tok;
	t_word	*word;

	tok = NULL;
	word = NULL;
	tok = init_token(pkg);
	tok->type = word_t;
	tok->token = init_word(pkg);
	word = cast_token(tok);
	word->str = str;
	return (0);
}

int	create_operator_token(t_meta *pkg, int type)
{
	t_token	*tok;
	t_op	*op;

	tok = NULL;
	op = NULL;
	tok = init_token(pkg);
	tok->type = op_t;
	tok->token = init_op(pkg);
	op = cast_token(tok);
	if (type == heredoc)
		capture_heredoc(pkg);
	op->type = type;
	op->fd_in = STDIN_FILENO;
	op->fd_out = STDOUT_FILENO;
	return (0);
}

int create_file_token(char *str, t_meta *pkg)
{
	t_token	*tok;
	t_file *file;

	tok = NULL;
	file = NULL;
	tok = init_token(pkg);
	tok->type = file_t;
	tok->token = init_file(pkg);
	file = cast_token(tok);
	file->name = str;
	file->fd = 0;
//	pkg->i += ft_strlen(str);
	return (0);
}
