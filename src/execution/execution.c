#include "minishell.h"

void	execution(t_meta *pkg)
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
	/*
	status = get_last_status(status, status_built);
	update_variable_status_process(env, status);
	if (env->verbose == 1)
		printf("=========\n");
	 */
}

int	execute_cmd(t_meta *pkg, t_token *token)
{
	t_cmd	*cmd;
	char	**variables;
	int		status_built;

	status_built = -1;
	if (token->type == TOK_CMD)
	{
		variables = get_env_variables(env);
		bin_execution(env, cmd, variables);
	}
	else if (token->type == TOK_BUILTIN)
	{
		status_built = built_in_execution(env, cmd);
	}
	return (status_built);
}

int	wait_all_pid(t_meta *pkg)
{
	t_token	*token;
	t_cmd	*cmd;
	int		status;

	token = get_first_token_cmd(pkg);
	status = 0;
	while (token)
	{
		cmd = get_class(token);
		waitpid(cmd->pid, &status, 0);
		status = convert_status_process_value(status);
		token = get_next_token_cmd(token);
	}
	return (status);
}
