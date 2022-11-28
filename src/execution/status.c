
#include "minishell.h"

int	get_last_status(int bin_status, int ret_built_in)
{
	if (ret_built_in == -1)
		return (bin_status);
	else if (bin_status == -1)
		return (ret_built_in);
	return (0);
}

int	convert_status_process_value(int status)
{
	if (WIFSIGNALED(status))
		status = WEXITSTATUS(status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

void	update_variable_status_process(t_meta *pkg, int status)
{
	char	*value;
	char	*env_val;

	value = ft_itoa(status);
	if (!value)
		return ;
	env_val = ft_getenv(pkg, "?");
	//env_val = get_env_var_with_name(env, "?");
	if (!env_val)
	{
		free(value);
		return ;
	}
	ft_setenv(pkg, "?", value);
}