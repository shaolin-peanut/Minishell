
#include "minishell.h"

void	use_signal(void)
{
	signal(SIGQUIT, pass);
	signal(SIGINT, call_prompt);
}

void	call_prompt(int key)
{
	/*
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	update_variable_status_process(g_pkg, 130);
	 */
	if (g_pkg->child_pid == 0)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		update_variable_status_process(g_pkg,1);
	}
	else
	{
		kill(g_pkg->child_pid, SIGINT);
		update_variable_status_process(g_pkg,128 + key);
	}
}

void	pass(int key)
{
	/*
	(void)key;
	rl_on_new_line();
	 */
	if (!g_pkg->child_pid)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		update_variable_status_process(g_pkg,128 + key);
		ft_putendl_fd("Quit: 3", 2);
	}
	g_pkg->child_pid = 0;
}
/*
void	add_signal_env_var(t_env *env)
{
	t_var	*signal_var;
	char	*value;
	char	*name;

	name = malloc_strcpy("?");
	value = malloc_strcpy("0");
	signal_var = init_env_variable(name, value, VALUE);
	add_new_env_variable(env, signal_var);
}
*/