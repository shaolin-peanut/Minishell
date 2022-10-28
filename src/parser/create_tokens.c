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
// int	is_dash(int c)
// {
// 	if (c == '-')
// 		return (1);
// 	else
// 		return (0);
// }

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
}

void	print_argument_vector(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i] != NULL)
		printf(">argv[%d]:%s\n", i, argv[i]);
}

t_builder	*init_builder(t_builder	*b, int i, char 	*str)
{
	b = (t_builder *)malloc(sizeof(t_builder));
	if (!b)
		return (NULL);
	b->index = i++;
	b->word = NULL;
	b->word = str;
	// Maybe malloc this in advance and always loop through on closure?
	b->next = NULL;
	return (b);
}

char	**build_argument_vector(char *name, t_meta *pkg)
{
	// 1. Identify the options and arguments of 
	// the programs, til next operator/separator
	char	**argument_vector;
	// char	**old;
	t_builder	*head;
	t_builder	*tmp;
	t_builder	*last;
	int		b_i;

	tmp = NULL;
	b_i = 0;
	head = init_builder(head, b_i, name);
	printf("head->word: %s\n", head->word);
	last = head;
	// move to whitespace
	while (is_blank(pkg->str, pkg->i) || is_word(pkg->str, pkg->i))
	{
		if (is_word(pkg->str, pkg->i))
		{
			tmp = init_builder(tmp, b_i, return_word(pkg->str, pkg));
			last->next = tmp;
			last = tmp;
		}
		if (is_blank(pkg->str, pkg->i))
			pkg->i++;
	}
	int i = -1;
	argument_vector = (char **)malloc(sizeof(char *) * last->index + 1);
	while (head != NULL)
	{
		argument_vector[]
	}
	print_argument_vector(argument_vector);
	free_argv(argument_vector);
}

int	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg)
{
	t_token	*tok;	
	t_cmd	*cmd;

	tok = NULL;
	tok = init_token(pkg);
	tok->type = TOK_CMD;
	tok->token = (t_cmd *) init_cmd;
	cmd = (t_cmd *) tok->token;
	cmd->binary_path = full_path;
	cmd->cmd_argv = build_argv(cmd_name, pkg);
	cmd->fd_in = last_node_fdin(pkg);
	cmd->fd_out = cmd->fd_in + 1;
	cmd->pid = NULL;
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
	if (type == TOK_HEREDOC)
		expand_heredoc(pkg);
	printf("operator created: %d\n", type);
	(void) pkg;
	return (0);
}
