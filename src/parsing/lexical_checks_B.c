/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/09/08 17:10:54 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_cmd(char	**str, int i)
{
	(void) str;
	(void) i;
	return (1);
}

int	is_builtin(char **str, int i)
{
	(void) str;
	(void) i;
	return (0);
}
