/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:43:34 by sbars             #+#    #+#             */
/*   Updated: 2022/11/08 15:58:23 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	errormsg(char *str, t_meta	*pkg)
{
	int	i;

	i = -1;
	(void) pkg;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
	return (-1);
}
