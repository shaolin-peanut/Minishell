/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:16:19 by sbars             #+#    #+#             */
/*   Updated: 2022/11/15 17:32:14 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_meta	*g_pkg;

int	main(int argc, char **argv, char **envp)
{
	t_meta		*pkg;

	(void) argc;
	(void) argv;
    pkg = init_meta(envp);
	g_pkg = pkg;
	prompt(pkg);
	free_all(pkg);
	return (0);
}
