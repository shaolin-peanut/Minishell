/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_char_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/11/01 18:02:53 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_blank(const char *str, int i)
{
	if (str[i] == 32 || str[i] == 9)
		return (1);
	return (0);
}

bool	is_dollar(char c)
{
	if (c == '$')
		return (1);
	else
		return (0);
}

bool	is_dollar_question(const char *str, int i)
{
	if (str[i] == '$' && str[i + 1] == '?')
		return (1);
	return (0);
}

bool	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (1);
	return (0);
}
