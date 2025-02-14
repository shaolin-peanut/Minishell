/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buil_in_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	built_in_execution(t_meta *pkg, t_bltn *cmd)
{
	int		status;
	char	*word;

	status = -1;
	word = cmd->argv[0];
	if (ft_strncmp(word, "echo", 5) == 0)
		status = echo(cmd);
	else if (ft_strncmp(word, "cd", 3) == 0)
		status = cd(cmd, pkg);
	else if (ft_strncmp(word, "env", 4) == 0)
		status = env_built_in(cmd, pkg);
	else if (ft_strncmp(word, "export", 7) == 0)
		status = export_built_in(cmd, pkg);
	else if (ft_strncmp(word, "unset", 6) == 0)
		status = unset(cmd, pkg);
	else if (ft_strncmp(word, "pwd", 4) == 0)
		status = pwd(cmd);
	else if (ft_strncmp(word, "exit", 5) == 0)
		status = exit_built_in(cmd, pkg);
	return (status);
}
