#include "minishell.h"

int	echo(t_bltn *cmd)
{
	int		i;
	bool	flag;

	i = 1;
	flag = false;
	if (cmd->argc > 1)
	{
		if (strncmp(cmd->argv[1], "-n", 2) == 0)
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

int	cd(t_bltn *cmd, t_meta *pkg)
{
	char	*path;
	char	*new_path;
	char	*last_path;

	if (cmd->argc < 2)
		path = getenv("HOME");
	else if (cmd->argc == 2)
		path = cmd->argv[1];
	else
	{
		perror("cd : too many arguments\n");
		return (1);
	}
	if (chdir(path) == -1)
	{
		printf("%s: No such file or directory\n", path);
		return (1);
	}
	new_path = get_current_path();
	last_path = getenv("PWD");
	//liste chainee de variables denvironnement?
	ft_setenv(pkg, "PWD", new_path);
	ft_setenv(pkg, "OLDPWD", last_path);
	return (0);
}

int	env_built_in(t_cmd *cmd, t_env *env)
{
	print_all_env_var_fd(env, cmd->fd_out);
	return (0);
}

int	pwd(t_cmd *cmd)
{
	char	*path;

	path = get_current_path();
	ft_putstr_fd(path, cmd->fd_out);
	ft_putstr_fd("\n", cmd->fd_out);
	free(path);
	return (0);
}

void	exit_built_in(t_cmd *cmd, t_env *env)
{
	int	signal;

	ft_putstr_fd("exit", 2);
	ft_putstr_fd("\n", 2);
	if (!cmd->arg)
		signal = 0;
	else
		signal = ft_atoi(cmd->arg);
	remove_all(env);
	exit(signal);
}
