/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	bin_execution(t_meta *pkg, t_cmd *cmd)
{
	int		pid;
	char	*path;

	path = cmd->binary_path;
	pid = fork();
	if (pid == 0)
	{
		if (!cmd_have_standart_fd(cmd))
		{
			redirect_cmd(cmd);
			close_all_fd(pkg);
		}
		execve(path, cmd->argv, pkg->envp);
		perror("Command failure : ");
		exit(1);
	}
	else
		cmd->pid = pid;
	pkg->child_pid = cmd->pid;
}
