/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:43:34 by sbars             #+#    #+#             */
/*   Updated: 2022/09/08 17:10:38 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"

int	errormsg(char *str, t_meta	*pkg)
{
	int	i;

	i = -1;
	(void) pkg;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	return (0);
}
