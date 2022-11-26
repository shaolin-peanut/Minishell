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

    pkg = init_meta(envp);
	while (argc || argv || envp)
    {
		pkg->str = NULL;
		pkg->i = 0;
		prompt_str = get_prompt();
        printf("------------parser\n");
		if (prompt_str)
			parser(readline(prompt_str), pkg);
		else
			parser(readline("guest@minishell $ "), pkg);
        free(prompt_str);
		print_all_tokens(pkg);
        printf("------------executor\n");
		executor(pkg);
		print_all_tokens(pkg);
        free_tokens(pkg);
	}
    free_all(pkg);
	return (0);
}
