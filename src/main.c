/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:16:19 by sbars             #+#    #+#             */
/*   Updated: 2022/11/11 17:16:26 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;

	(void) argv;
	prompt.commands = NULL;
	prompt.envp = ft_dup_matrix(envp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	t_meta		*pkg;
	char		*prompt_str;

	while (argc || argv || envp)
	{
		prompt = init_prompt(argv, envp);
		pkg = init_meta(&prompt);
		prompt_str = get_prompt(prompt);
		if (prompt_str)
			parser(readline(prompt_str), pkg);
		else
			parser(readline("guest@minishell $ "), pkg);
		print_all_tokens(pkg);
		executor(pkg);
		free(prompt_str);
		free_all(pkg);
	}
	return (0);
}
