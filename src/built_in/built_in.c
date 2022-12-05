/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	echo(t_bltn *cmd)
{
	int		i;
	bool	flag;

	i = 1;
	flag = false;
	if (cmd->argc > 1)
	{
		if (ft_strncmp(cmd->argv[1], "-n", 2) == 0)
		{
			flag = true;
			i++;
		}
		while (i < cmd->argc)
		{
			ft_putstr_fd(cmd->argv[i], cmd->fd_out);
			++i;
		}
	}
	if (!flag)
		ft_putstr_fd("\n", cmd->fd_out);
	return (0);
}

char	*check_cd(t_bltn *cmd, t_meta *pkg)
{
	char	*path;

	if (cmd->argc < 2)
		path = ft_getenv(pkg, "HOME");
	else if (cmd->argc == 2)
		path = cmd->argv[1];
	else
	{
		errno = E2BIG;
		perror("cd");
		return (NULL);
	}
	if (chdir(path) == -1)
	{
		perror(path);
		return (NULL);
	}
	return (path);
}

int	cd(t_bltn *cmd, t_meta *pkg)
{
	char	*path;
	char	*new_path;
	char	*last_path;

	path = check_cd(cmd, pkg);
	if (!path)
		return (1);
	new_path = get_current_path();
	last_path = ft_getenv(pkg, "PWD");
	ft_setenv(pkg, "PWD", new_path);
	ft_setenv(pkg, "OLDPWD", last_path);
	if (cmd->argc < 2)
		free(path);
	free(new_path);
	free(last_path);
	return (0);
}

int	env_built_in(t_bltn *bltn, t_meta *pkg)
{
	ft_putmatrix_fd(pkg->envp, 1, bltn->fd_out);
	return (0);
}

int	pwd(t_bltn *cmd)
{
	char	*path;

	path = get_current_path();
	ft_putstr_fd(path, cmd->fd_out);
	ft_putstr_fd("\n", cmd->fd_out);
	free(path);
	return (0);
}
