/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:47:12 by sbars             #+#    #+#             */
/*   Updated: 2022/11/11 18:10:26 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if (pkg->prompt)
	//    free(pkg->prompt);
	/*if (pkg->str)
	{
		pkg->str = NULL;
		free(pkg->str);
	}*/

void	free_cmd(t_token	*tok)
{
	t_cmd	*cmd;
	t_bltn	*bltn;

	cmd = NULL;
	bltn = NULL;
	if (tok->type == TOK_CMD)
	{
		cmd = cast_token(tok);
		if (cmd->argv)
			free_str_vector(cmd->argv);
		if (cmd->binary_path)
			free(cmd->binary_path);
		free((void *) cmd);
//		free(tok);
	}
	else if (tok->type == TOK_BUILTIN)
	{
		bltn = cast_token(tok);
		if (bltn->argv)
			free_str_vector(bltn->argv);	
		free((void *) bltn);
//		free(tok);
	}
}

void	free_word(t_token	*tok)
{
	t_word	*word;

	word = NULL;
	word = cast_token(tok);
	if (word->str)
		free(word->str);
	free((void *) word);
//	free(tok);
}

void	free_tokens(t_token	*head)
{
	t_token	*current;

	if (!head)
		return ;
	current = head;
	while (head != NULL)
	{
		if (current->type == TOK_CMD || current->type == TOK_BUILTIN)
			free_cmd(current);
		else if (current->type == TOK_WORD)
			free_word(current);
		if (current)
			free(current);
		head = head->next;
		current = head;
	}
}

void	free_all(t_meta *pkg)
{
	if (pkg->paths != NULL)
		free(pkg->paths);
	if (pkg->chain_head)
		free_tokens(pkg->chain_head);
	if (pkg)
		free(pkg);
}
