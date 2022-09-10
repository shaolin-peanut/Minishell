/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:54:40 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/10 16:58:18 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* reads the command line such as “ls ­al”
puts it into a data structure called Command Table
that will store the commands that will be executed.*/
void	parser(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}
