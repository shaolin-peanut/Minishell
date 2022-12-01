#include "minishell.h"

void	executor(t_meta *pkg)
{
	t_token	*token;
	int		status;
	int		status_built;
	char	*val;

	status_built = -1;
	token = get_first_token_cmd(pkg);
	while (token)
	{
		status_built = execute_cmd(pkg, token);
		token = get_next_token_cmd(token);
	}
	close_all_fd(pkg);
	if (is_token_heredoc(pkg))
		remove_tmp_file(pkg);
	status = wait_all_pid(pkg);
	pkg->last_exit_status = get_last_status(status, status_built);
	val = ft_itoa(pkg->last_exit_status);
	ft_setenv(pkg, "?", val);
	free(val);
}

int	execute_cmd(t_meta *pkg, t_token *token)
{
	t_cmd	*cmd;
	t_bltn	*bltn;
	int		status_built;

	status_built = -1;
	if (token->type == cmd_t)
	{
		cmd = cast_token(token);
		bin_execution(pkg, cmd);
	}
	else if (token->type == builtin_t)
	{
		bltn = cast_token(token);
		status_built = built_in_execution(pkg, bltn);
	}
	return (status_built);
}

int	wait_all_pid(t_meta *pkg)
{
	t_token	*token;
	t_cmd	*cmd;
	int		status;

	token = get_first_token_cmd(pkg);
	status = -1;
	while (token)
	{
		if(token->type == cmd_t)
		{
			cmd = cast_token(token);
			//printf("waiting for pid cmd -> %d\n", cmd->pid);
			waitpid(cmd->pid, &status, 0);
		}
		status = convert_status_process_value(status);
		token = get_next_token_cmd(token);
	}
	pkg->child_pid = 0;
	return (status);
}
