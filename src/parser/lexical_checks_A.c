/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_A.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:11:14 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_dollar(char c)
{
	if (c == '$')
		return (1);
	else
		return (0);
}

int	is_quote(char c)
{
	if (c == 39 || c == 34)
		return (1);
	return (0);
}

//TODO: Debug and complete this function
int	is_var(char	*str, int i)
{
	return (is_dollar(str[i] && is_word(str, i + 1)));
}

int	is_word(char	*str, int i)
{
	return (str[i] != '\0' && !is_blank(str, i) && !is_operator(str, i) && !is_dollar(str[i]));
}