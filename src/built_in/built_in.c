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
		path = ft_getenv(pkg, "HOME");
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
	last_path = ft_getenv(pkg, "PWD");
	//liste chainee de variables denvironnement?
	ft_setenv(pkg, "PWD", new_path);
	ft_setenv(pkg, "OLDPWD", last_path);
	//free my bitches? somewhere??
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

/*
 * draft exit
 * if (argc == 1)
 * 		exit and signal = 0
 * if (argc > 2)
 * 	print (bash: exit: too many arguments)
 * 	flag false
 * else if (== 2 && is_digit(argv[1])
 *    signal = 255;
 *    printf(num argument required
 */

void	minishell_exit(int exit_code, t_meta *pkg)
{
	ft_putendl_fd("exit", 2);
	free_tokens(pkg);
	free_all(pkg);
	clear_history();
	exit(exit_code);
}

void	exit_built_in(t_bltn *bltn, t_meta *pkg)
{
	if (bltn->argc == 1)
		minishell_exit(0, pkg);
	else if (bltn->argc == 2)
	{
		if (ft_isdigit_str(bltn->argv[1]) == 0)
		{
			ft_putstr_fd(bltn->argv[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			minishell_exit(255, pkg);
		}
		else if (bltn->argc == 2)
			minishell_exit(ft_atoi(bltn->argv[1]), pkg);
	}
	else
		ft_putendl_fd("exit: too many arguments", 2);
}
/*
	 x exit -> signal = 0;
	 x exit number -> signal = number;
	 x exit number anything -> doesn-t exit , prints exit\n too many args
	 x exit notanumber -> signal = 255 and prints numeric argument required
	 * exit notanumber  anyhing -> signal = 255 and prints numeric argument required
	 */