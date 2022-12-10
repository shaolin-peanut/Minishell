/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:16:45 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:09:40 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_cmd_token(t_token	*tok)
{
	t_cmd	*cmd;

	cmd = cast_token(tok);
	printf("|> TOKEN:CMD\n");
	printf("|> binary_path:%s\n", cmd->binary_path);
	printf("|> argc:%d\n", cmd->argc);
	print_2d_vector(cmd->argv);
	printf("|> fd_in:%d\n", cmd->fd_in);
	printf("|> fd_out:%d\n", cmd->fd_out);
	printf("|> pid: %d\n", cmd->pid);
}

void	print_operator_tok(t_token	*tok)
{
	t_op	*op;

	op = cast_token(tok);
	printf("|> TOKEN:OPERATOR\n");
	if (op->type == pipe_t)
		printf("|> type: pipe\n");
	if (op->type == heredoc)
		printf("|> type: heredoc\n");
	if (op->type == redir_in)
		printf("|> type: input redirection\n");
	if (op->type == redir_out)
		printf("|> type: output redirection\n");
	printf("|> fd_in:%d\n", op->fd_in);
	printf("|> fd_out:%d\n", op->fd_out);
}

void	print_word(t_token	*tok)
{
	t_word	*w;

	w = cast_token(tok);
	printf("|> TOKEN:WORD\n");
	printf("|> str: %s$\n", w->str);
}

void	print_builtin_token(t_token	*tok)
{
	t_bltn	*b;

	b = cast_token(tok);
	printf("|> TOKEN:BUILTIN\n");
	printf("|> name: %s\n", b->argv[0]);
	if (b->argv)
		print_2d_vector(b->argv);
	printf("|> fd_in:%d\n", b->fd_in);
	printf("|> fd_out:%d\n", b->fd_out);
	printf("|> pid: %d\n", b->pid);
}

void	print_all_tokens(t_meta	*pkg)
{
	t_token	*token;

	token = pkg->chain_head;
	while (token != NULL)
	{
		printf("---\n");
		if (token->type == cmd_t)
			print_cmd_token(token);
		if (token->type == builtin_t)
			print_builtin_token(token);
		if (token->type == op_t)
			print_operator_tok(token);
		if (token->type == file_t)
			print_file_token(token);
		token = token->next;
	}
}
