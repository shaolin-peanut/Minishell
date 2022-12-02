/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	use_signal(void)
{
	signal(SIGQUIT, pass);
	signal(SIGINT, call_prompt);
}

void	call_prompt(int key)
{
	if (g_pkg->child_pid == 0)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		update_variable_status_process(g_pkg, 1);
	}
	else
	{
		kill(g_pkg->child_pid, SIGINT);
		update_variable_status_process(g_pkg, 128 + key);
	}
}

void	pass(int key)
{
	if (!g_pkg->child_pid)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		update_variable_status_process(g_pkg, 128 + key);
		ft_putendl_fd("Quit: 3", 2);
	}
	g_pkg->child_pid = 0;
}
