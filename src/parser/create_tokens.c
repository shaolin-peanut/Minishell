/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/11/02 17:59:43 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// int	is_dash(int c)
// {
// 	if (c == '-')
// 		return (1);
// 	else
// 		return (0);
// }

// TODO: code last_node_fd_in function
// TODO: figure out what to do with pid thing, or delete
int	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;	
	t_cmd	*cmd;

	cmd = NULL;
	tok = NULL;
	tok = init_token(pkg);
	tok->type = TOK_CMD;
	tok->token = init_cmd(pkg);
	cmd = cast_token(tok);
	cmd->binary_path = full_path;
	cmd->argv = build_argument_vector(cmd_name, pkg);
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	//cmd->pid = NULL;
	//printf("> Cmd found!: %s\n> binary path: %s\n", cmd_name, full_path);
	return (0);
}

int	create_builtin_token(char *name, t_meta	*pkg)
{
	t_token		*tok;
	t_bltn		*builtin;

	tok = NULL;
	builtin = NULL;
	tok = init_token(pkg);
	tok->type = TOK_BUILTIN;
	tok->token = init_builtin(pkg);
	builtin = cast_token(tok);
	builtin->argv = build_argument_vector(name, pkg);
	builtin->fd_in = STDIN_FILENO;
	builtin->fd_out = STDOUT_FILENO;
	return (1);
}

int	create_word_token(char *str, t_meta *pkg)
{
	t_token	*tok;
	t_word	*word;

	tok = NULL;
	word = NULL;
	tok = init_token(pkg);
	tok->type = TOK_WORD;
	tok->token = init_word(pkg);
	word = cast_token(tok);
	word->str = str;
	return (0);
}

// TODO: finish this one
int	create_operator_token(t_meta *pkg, int type)
{
	t_token	*tok;
	t_op	*op;

	tok = NULL;
	op = NULL;
	tok = init_token(pkg);
	tok->type = TOK_OP;
	tok->token = init_op(pkg);
	op = cast_token(tok);
	if (type == TOK_HEREDOC)
		expand_heredoc(pkg);
		// create heredoc operator token, and in expand heredoc, create a following word token
		// heredoc fd-in = expanded text between the delimiter
		// heredoc fd-out = command before that
	op->type = type;
	op->fd_in = STDIN_FILENO;
	op->fd_out = STDOUT_FILENO;
	return (0);
}
