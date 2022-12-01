#include "minishell.h"

void	bin_execution(t_meta *pkg, t_cmd *cmd)
{
	int		pid;
	char	*path;

	path = cmd->binary_path;
	pid = fork();
	if (pid == 0)
	{
		//printf("executing %s, with fd(%d, %d) and pid %d\n",path ,cmd->fd_in, cmd->fd_out, pid);
		if (!cmd_have_standart_fd(cmd))
		{
			//printf("Passed here\n");
			redirect_cmd(cmd);
			close_all_fd(pkg);
		}
		execve(path, cmd->argv, pkg->envp);
		perror("Command failure : ");
		exit(1);
	}
	else
	{
		//printf("executing %s, with fd(%d, %d) and pid %d\n",path ,cmd->fd_in, cmd->fd_out, pid);
		//printf("changed pid to -> %d\n", pid);
		cmd->pid = pid;
	}
	pkg->child_pid = cmd->pid;
}
