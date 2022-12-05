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

int	check_cmd(t_cmd *cmd)
{
	if (access(cmd->binary_path, F_OK))
	{
		ft_putstr_fd("minishell: Command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmd->argv[0], STDERR_FILENO);
		g_pkg->last_exit_status = 127;
		return (1);
	}
	if (access(cmd->binary_path, X_OK) && cmd->binary_path)
	{
		ft_putstr_fd("minishell: Permission denied: ", STDERR_FILENO);
		ft_putendl_fd(cmd->binary_path, STDERR_FILENO);
		g_pkg->last_exit_status= 126;
		return (2);
	}
	return (0);
}

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
//		perror(path);
		exit(1);
	}
	else
		cmd->pid = pid;
	pkg->child_pid = cmd->pid;
}
