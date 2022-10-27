/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/10/27 17:03:00 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;	

	(void) cmd_name;
	(void) full_path;
	tok = NULL;
	tok = init_token(pkg);
	tok->type = TOK_CMD;
	tok->token = init_cmd;
	//printf("> Cmd found!: %s\n> binary path: %s\n", cmd_name, full_path);
	if (full_path)
	{
		free(full_path);
		full_path = NULL;
	}
	(void) pkg;
	return (0);
}

int	create_builtin_token(char *cmd_name, t_meta *pkg)
{
	printf("> Builtin found!: %s\n>", cmd_name);
	(void) pkg;
	return (0);
}

int	create_alien_word_token(char *word, t_meta *pkg)
{
	(void) word;
	(void) pkg;
	return (0);
}

int	create_operator_token(t_meta *pkg, int type)
{
	printf("operator created: %d", type);
	(void) pkg;
	return (0);
}
