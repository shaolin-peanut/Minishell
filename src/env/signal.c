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
		g_pkg->last_exit_status = (1);
	}
	else
	{
		kill(g_pkg->child_pid, SIGINT);
		g_pkg->last_exit_status = (128 + key);
		//g_pkg->last_exit_status = (130);
		printf("last exit status in signal %d\n", g_pkg->last_exit_status);
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
		g_pkg->last_exit_status = (128 + key);
		ft_putendl_fd("Quit: 3", 2);
	}
	g_pkg->child_pid = 0;
}
