#include "minishell.h"

int	echo(t_bltn *cmd)
{
	if (!cmd->argv)
	{
		ft_putstr_fd("\n", cmd->fd_out);
		return (0);
	}
	ft_putstr_fd(cmd->argv[0], cmd->fd_out);
	if (!(cmd_have_flags(cmd)))
		ft_putstr_fd("\n", cmd->fd_out);
	return (0);
}

int	cd(t_bltn *cmd, t_meta *pkg)
{
	char	*path;
	char	*new_path;
	char	*last_path;

	if (!cmd->argv)
		return (0);
	path = cmd->argv[0];
	if (chdir(path) == -1)
	{
		ft_printf("%s: No such file or directory\n", path);
		return (1);
	}
	new_path = get_current_path();
	last_path = get_last_path(env);
	change_env_var_value_with_name(env, "PWD", new_path);
	change_env_var_value_with_name(env, "OLDPWD", last_path);
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
