/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/08 17:08:37 by sbars            ###   ########.fr       */
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

static t_meta	*init_meta(t_prompt	*prompt)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *) malloc(sizeof(meta) * 1);
	meta->prompt = prompt;
	return (meta);
}

int	main(int argc, char **argv, char **envp)
{
	char		*cwd;
	t_prompt	prompt;
	t_meta		*pkg;

	prompt = init_prompt(envp);
	pkg = init_meta(&prompt);
	cwd = getcwd(NULL, 0);
	while (argc || argv || envp)
	{
		parser(readline(cwd), pkg);
//		chain = parser(readline(cwd));
//		if (chain != NULL)
//			executor(chain);
	}
	free(cwd);
	return (0);
}
