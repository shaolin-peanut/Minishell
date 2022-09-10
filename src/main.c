/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/10 17:45:28 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt	init_prompt(char **envp)
{
	t_prompt	prompt;

	prompt.commands = NULL;
	prompt.envp = ft_matrixdup(envp);
	return (prompt);
}

char	*get_prompt()
{
	char	*cwd;
	char	*str;

	cwd = getcwd(NULL, 0);
	free(cwd);
	str = ft_strjoin(cwd, " $ ");
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	char		*prompt_str;

	prompt = init_prompt(envp);
	while (argc || argv || envp)
	{
		prompt_str = get_prompt();
		readline(prompt_str);
	}
	free(prompt_str);
	(void) prompt;
	return (0);
}
