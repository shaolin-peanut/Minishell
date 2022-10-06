/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:22:00 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_blank(char *str, int i)
{
	if (str[i] == ' ' || str[i] == '	')
		return (1);
	return (0);
}

int is_redirection(char *str, int i)
{
	if (str[i] == '<' || str[i] == '>' || (str[i] == '>' && str[i + 1] == '>'))
		return (1);
	return (0);
}

int is_heredoc(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (1);
	return (0);
}

int	is_operator(char *str, int i)
{
	if (str[i] == '|' || is_redirection(str, i))
		return (1);
	return (0);
}

int	is_dollar_question(char *str, int i)
{
	if (str[i] != '$' || str[i + 1] != '?')
		return (0);
	return (1);
}
