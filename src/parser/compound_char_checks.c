/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_char_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 13:12:27 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_word(char	*str, int i)
{
	return (str[i] != '\0' && !is_blank(str, i)
		&& !is_operator(str, i) && !is_dollar(str[i]));
}

int	is_var(char	*str, int i)
{
	return (is_dollar(str[i] && is_word(str, i + 1)));
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

int	is_operator(char *str, int i)
{
	if (str[i] == '|' || is_redirection(str, i) || is_heredoc(str, i))
		return (1);
	return (0);
}
