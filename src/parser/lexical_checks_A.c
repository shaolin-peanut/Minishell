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
/*int	is_var(char	*str, int i)
{
	int	temp_i;

	temp_i = i;
	if (str[temp_i] != '$')
		return (0);
	temp_i++;
	while (str[i] && !is_blank(str, temp_i) && !is_operator(str, temp_i) && !is_dollar(str[i]))
	{
		temp_i++;
	}
	if (temp_i > i)
		return (temp_i);
	else
		return (0);
}*/

int	is_word(char	*str, int i)
{
	int	i_backup;

	i_backup = i;
	while (str[i] != '\0' && ft_isalnum(str[i]) && !is_blank(str, i) && !is_operator(str, i))
	{
//		if (is_quote(str[i]))
//				i = closed_quotes_len(str, i);
		i++;
	}
	if (i > i_backup)
		return (i);
	return (0);
}
