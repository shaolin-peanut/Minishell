/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/25 21:46:42 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;

	(void) argv;
	prompt.commands = NULL;
	prompt.envp = ft_matrixdup(envp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	t_meta		*pkg;
	char		*prompt_str;

	prompt = init_prompt(argv, envp);
	while (argc || argv || envp)
	{
		pkg = init_meta(&prompt);
		prompt_str = get_prompt(prompt);
		if (prompt_str)
			parser(readline(prompt_str), pkg);
		else
			parser(readline("guest@minishell $ "), pkg);
		free(prompt_str);
		free(pkg);
//	chain = parser(readline(cwd));
//	if (chain != NULL)
//     executor(chain);
	}
	return (0);
}
