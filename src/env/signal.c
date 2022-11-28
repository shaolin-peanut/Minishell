
#include "minishell.h"

void	use_signal(void)
{
	signal(SIGQUIT, pass);
	signal(SIGINT, call_prompt);
}

void	call_prompt(int key)
{
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	update_variable_status_process(g_pkg, 130);
}

void	pass(int key)
{
	(void)key;
	rl_on_new_line();
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