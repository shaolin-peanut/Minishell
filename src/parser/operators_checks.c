/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:57:09 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 15:09:25 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *str, int i)
{
	if (is_pipe(str[i]) || is_redirection(str, i) || is_heredoc(str, i))
		return (1);
	return (0);
}

int	is_redirection(char *str, int i)
{
	if (str[i] == '<' || str[i] == '>' || (str[i] == '>' && str[i + 1] == '>'))
		return (1);
	return (0);
}

int	is_heredoc(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
