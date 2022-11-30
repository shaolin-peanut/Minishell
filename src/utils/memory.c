/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:47:12 by sbars             #+#    #+#             */
/*   Updated: 2022/11/23 13:13:55 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_cmd(t_token	*tok)
{
	t_cmd	*cmd;
	t_bltn	*bltn;

	if (tok->type == cmd_t)
	{
		cmd = cast_token(tok);
		if (cmd->argv)
			free_str_vector(cmd->argv);
		if (cmd->binary_path)
			free(cmd->binary_path);
		free((void *) cmd);
	}
	else if (tok->type == builtin_t)
	{
		bltn = cast_token(tok);
		if (bltn->argv)
			free_str_vector(bltn->argv);
		free((void *) bltn);
	}
}

void	free_word(t_token	*tok)
{
	t_word	*word;

	word = NULL;
	word = cast_token(tok);
	if (word->str && ft_strlen(word->str) > 0)
		free(word->str);
	free(word);
}

void	free_op(t_token *tok)
{
	t_op *op;

	op = NULL;
	op = cast_token((tok));
	op->type = 0;
	free(op);
}

void	free_file(t_token *tok)
{
	t_file *file;

	file = NULL;
	file = cast_token((tok));
	if (file)
	{
		if (file->name)
			free(file->name);
		close(file->fd);
		free(file);
	}
}

void	free_token(t_token *self)
{
	if (self->type == cmd_t || self->type == builtin_t)
		free_cmd(self);
	else if (self->type == word_t)
		free_word(self);
	else if (self->type == op_t)
		free_op(self);
//	else if (self->type == file_t)
//		free_file(self);
	//@todo, free operator ''' and so on
	free (self);
}

void	free_tokens(t_meta 	*pkg)
{
	t_token *curr;
	t_token *prev;

	curr = return_last_token(pkg);
	while (curr)
	{
		prev = curr->prev;
		free_token(curr);
		curr = prev;
	}
	pkg->chain_head = NULL;
}

void	free_all(t_meta *pkg)
{
	if (pkg->paths != NULL)
		free_str_vector(pkg->paths);
	if (pkg->envp)
		free_str_vector(pkg->envp);
//	if (pkg->chain_head)
//		free_tokens(pkg->chain_head);
	free(pkg);
}
