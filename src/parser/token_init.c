/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:19:35 by sbars             #+#    #+#             */
/*   Updated: 2022/10/31 12:10:52 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(t_meta	*pkg)
{
	t_cmd	*command;

	command = (t_cmd *) malloc(sizeof(t_cmd) * 1);
	if (!command)
		errormsg("malloc error in init_cmd\n", pkg);
	command->binary_path = 0;
	command->argv = 0;
	command->fd_in = 0;
	command->fd_out = 0;
	return (command);
}

t_bltn	*init_builtin(t_meta	*pkg)
{
	t_bltn	*builtin;

	builtin = (t_bltn *) malloc(sizeof(t_bltn) * 1);
	if (!builtin)
		errormsg("malloc error in init-builtin\n", pkg);
	builtin->argv = 0;
	builtin->fd_in = 0;
	builtin->fd_out = 0;
	return (builtin);
}

t_op	*init_op(t_meta	*pkg)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op) * 1);
	if (!op)
		errormsg("malloc error in init_op\n", pkg);
	op->type = 0;
	op->fd_in = 0;
	op->fd_out = 0;
	return (op);
}

t_word	*init_word(t_meta	*pkg)
{
	t_word	*word;

	word = (t_word *)malloc(sizeof(t_word) * 1);
	if (!word)
		errormsg("malloc error in init_op\n", pkg);
	word->str = NULL;
	return (word);
}
