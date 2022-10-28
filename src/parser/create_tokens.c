/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:22 by sbars             #+#    #+#             */
/*   Updated: 2022/10/28 15:37:05 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// int	is_dash(int c)
// {
// 	if (c == '-')
// 		return (1);
// 	else
// 		return (0);
// }

// TODO: code last_node_fd_in function
// TODO: figure out what to do with pid thing, or delete
int	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;	
	t_cmd	*cmd;

	cmd = NULL;
	tok = NULL;
	tok = init_token(pkg);
	tok->type = TOK_CMD;
	tok->token = init_cmd(pkg);
	cmd = cast_token(tok);
	cmd->binary_path = full_path;
	cmd->cmd_argv = build_argument_vector(cmd_name, pkg);
	cmd->fd_in = 0;
	//cmd->fd_in = last_node_fdin(pkg);
	cmd->fd_out = cmd->fd_in + 1;
	//cmd->pid = NULL;
	//printf("> Cmd found!: %s\n> binary path: %s\n", cmd_name, full_path);
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
	if (type == TOK_HEREDOC)
		expand_heredoc(pkg);
	printf("operator created: %d\n", type);
	(void) pkg;
	return (0);
}
