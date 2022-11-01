/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_char_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/11/01 18:03:35 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_word(char	*str, int i)
{
	return (str[i] != '\0' && !is_blank(str, i)
		&& !is_operator(str, i) && !is_dollar(str[i]));
}

bool	is_var(char	*str, int i)
{
	//printf("str[i]:%c\nstr[i + 1]:%c", str[i], str[i + 1]);
	//printf("is_dollar:%b, is_word:%b, !is_dollar_question", is_dollar(str[i]), is_word(str, i + 1), !is_dollar_question))
	return (is_dollar(str[i]) && is_word(str, i + 1)
		&& !is_dollar_question(str, i));
}
