/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2022/11/02 17:26:34 by sbars            ###   ########.fr       */
/*   Updated: 2022/10/26 13:48:37 by lanlan           ###   ########.fr       */
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
