#include "minishell.h"

void	executor(t_meta *pkg)
{
	t_token	*token;
	int		status;
	int		status_built;

	token = get_first_token_cmd(pkg);
	while (token)
	{
		status_built = execute_cmd(pkg, token);
		token = get_next_token_cmd(token);
	}
	close_all_fd(pkg);
	status = wait_all_pid(pkg);
	pkg->last_exit_status = get_last_status(status, status_built);
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
		//variables = get_env_variables(env);
		//update_envp(pkg);
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
	t_bltn	*bltn;
	int		status;

	token = get_first_token_cmd(pkg);
	status = 0;
	while (token)
	{
		if(token->type == builtin_t)
		{
			bltn = cast_token(token);
			waitpid(bltn->pid, &status, 0);
		}
		else if(token->type == cmd_t)
		{
			cmd = cast_token(token);
			waitpid(cmd->pid, &status, 0);
		}
		status = convert_status_process_value(status);
		token = get_next_token_cmd(token);
	}
	return (status);
}
