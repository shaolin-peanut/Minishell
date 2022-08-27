/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/08/27 17:30:06 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*cwd;
	t_prompt	prompt;

	cwd = getcwd(NULL, 0);
	while (argc || argv || envp)
	{
		readline(cwd);
	}
	return (0);
}
