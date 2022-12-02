/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	minishell_exit(int exit_code, t_meta *pkg)
{
	ft_putendl_fd("exit", 2);
	free_tokens(pkg);
	free_all(pkg);
	clear_history();
	exit(exit_code);
}

int	exit_built_in(t_bltn *bltn, t_meta *pkg)
{
	if (bltn->argc == 1)
		minishell_exit(0, pkg);
	else if (bltn->argc == 2)
	{
		if (ft_isdigit_str(bltn->argv[1]) == 0)
		{
			ft_putstr_fd(bltn->argv[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			minishell_exit(255, pkg);
		}
		else
			minishell_exit(ft_atoi(bltn->argv[1]), pkg);
	}
	else
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (257);
	}
	return (0);
}
