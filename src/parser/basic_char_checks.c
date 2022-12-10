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
		return (true);
	return (false);
}

bool	is_dollar(char c)
{
	if (c == '$')
		return (true);
	else
		return (false);
}

bool	is_single_quote(char c)
{
	if (c == 39)
		return (true);
	return (false);
}

bool	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (true);
	return (false);
}
