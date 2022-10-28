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
	command->cmd_argv = 0;
	command->fd_in = 0;
	command->fd_out = 0;
	command->pid = 0;
	return (command);
}
