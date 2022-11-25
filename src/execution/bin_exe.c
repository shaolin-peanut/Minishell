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
}
