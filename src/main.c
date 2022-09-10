/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/10 22:05:56 by lanlan           ###   ########.fr       */
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

char	*get_prompt(t_prompt prompt)
{
	char	*temp;
	char	*temp2;
	char	*home;

	(void) prompt;
	// temp = get_user(prompt);
	temp = ft_strdup("lanlan");
	temp2 = ft_strjoin(temp, "@minishell ");
	free(temp);
	// home = get_home(prompt);
	home = getcwd(NULL, 0);
	temp = ft_strjoin(temp2, home);
	free(home);
	free(temp2);
	temp2 = ft_strjoin(temp, "$ ");
	free(temp);
	return (temp2);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	char		*prompt_str;

	prompt = init_prompt(argv, envp);
	while (argc || argv || envp)
	{
		prompt_str = get_prompt(prompt);
		if (prompt_str)
			readline(prompt_str);
		else
			readline("guest@minishell $ ");
		free(prompt_str);
	}
	return (0);
}
