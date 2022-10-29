/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:19:35 by sbars             #+#    #+#             */
/*   Updated: 2022/10/28 14:05:36 by sbars            ###   ########.fr       */
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

t_builtin	*init_builtin(t_meta	*pkg)
{
	t_builtin	*builtin;

	builtin = (t_builtin *) malloc(sizeof(t_builtin) * 1);
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