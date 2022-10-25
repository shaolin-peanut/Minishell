/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_char_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 15:10:43 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_blank(char *str, int i)
{
	if (str[i] == 32 || str[i] == 9)
		return (1);
	return (0);
}

int	is_dollar(char c)
{
	if (c == '$')
		return (1);
	else
		return (0);
}

int	is_dollar_question(char *str, int i)
{
	if (str[i] != '$' || str[i + 1] != '?')
		return (0);
	return (1);
}

int	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (1);
	return (0);
}
