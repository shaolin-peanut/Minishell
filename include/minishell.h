/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by lanlan            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/10 14:27:50 by sbars            ###   ########.fr       */
=======
/*   Updated: 2022/10/26 13:48:48 by lanlan           ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "parser.h"
# include "token.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_prompt
{
	t_list	*commands;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_meta
{
	t_prompt	*prompt;
	char		**paths;
	char		*str;
	int			i;
	t_token		*chain_head;
}			t_meta;

// parser/
// parser.c
t_token		*parser(char *str, t_meta *pkg);

// prompt.c
char		*get_prompt(t_prompt prompt);
// For further parser prototypes, see parser.h

// utils/

// error.c
int			errormsg(char *str, t_meta	*pkg);

// init.c
t_meta		*init_meta(t_prompt *prompt);
char		**init_paths(t_meta	*pkg);
t_token		*init_token(t_meta *pkg);

// memory.c
void		free_all(t_meta *pkg);

// list_utils.c
t_token		*return_last_token(t_meta	*pkg);
void		free_list(t_builder	*node);
void		*cast_token(t_token	*token);
char		**convert_list_to_vector(t_builder *head, int size);
void		print_2d_vector(char **argv);

// build_argv.c
char		**build_argument_vector(char *name, t_meta *pkg);
t_builder	*init_builder(int *i, char *str);
t_builder	*add_to_back_of_list(int *counter, t_builder *head, char *word);

// parser
void		smart_iter(int *a, int *b, int incr_a, int incr_b);

// executor/
// executor.c
void		executor(t_meta *pkg);

// == TEMPORARY ==

// testing.c
void		print_cmd_token(t_token	*tok);
void		print_operator_tok(t_token	*tok);
void		print_all_tokens(t_meta	*pkg);

#endif
