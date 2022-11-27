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

int	main(int argc, char **argv, char **envp)
{
	t_meta		*pkg;
	char		*prompt_str;
	char 		*line;

	int fdtest = open("outfile", O_WRONLY | O_TRUNC);
	printf("FDTEST = %d\n", fdtest);
	close(fdtest);
    pkg = init_meta(envp);
	while (argc || argv || envp)
    {
		pkg->str = NULL;
		pkg->i = 0;
		use_signal();
		prompt_str = get_prompt();
		if (prompt_str)
		{
			line = readline(prompt_str);
			free(prompt_str);
		}
		else
			line = readline("guest@minishell $ ");
		add_history(line);
		parser(line, pkg);
		printf("--parser DONE\n");
		processing_redirection(pkg);
		printf("--redirection DONE\n");
		//print_all_tokens(pkg);
		executor(pkg);
		printf("--execution DONE\n");
        free_tokens(pkg);
	}
    free_all(pkg);
	return (0);
}
