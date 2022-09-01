/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/08/30 17:44:36 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int is_space_tab(char *str, int i)
{
	if (str[i] == ' ' || str[i] == 9)
		return (1);
	return (0);
}

int	is_squote(char	*str, int i)
{
	if (str[i] == 39)
		return (1);
	return (0);
}

int	is_dquote(char	*str, int i)
{
	if (str[i] == 34)
		return (1);
	return (0);
}

int	is_dollar_sign(char	*str, int i)
{
	if (str[i] == '$')
		return (1);
	else
		return (0);
}

int	is_word(char	*str, int i)
{
	if (!ft_isalnum(str[i]))
			return (0);
	while (ft_isalnum(str[i]) && str[i])
		i++;
	return (i);
}
