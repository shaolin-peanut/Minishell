/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:29:42 by lanlan            #+#    #+#             */
/*   Updated: 2022/08/27 17:50:21 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_prompt	init_prompt(char **envp)
{
	t_prompt	prompt;

	prompt.commands = NULL;
	prompt.envp = ft_matrixdup(envp);
	return (prompt);
}
