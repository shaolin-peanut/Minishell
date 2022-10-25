/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_char_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 15:10:05 by sbars            ###   ########.fr       */
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
