/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by sbars             #+#    #+#             */
/*   Updated: 2022/11/15 17:30:22 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "parser.h"
# include "token.h"
# include "execution.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <termios.h>

extern t_meta	*g_pkg;

typedef struct s_meta
{
	char		**envp;
	char		**paths;
	char		*str;
	int			i;
	t_token		*chain_head;
	int			last_exit_status;
}			t_meta;

// pid_t	pid;

// parser/
// parser.c
bool		parser(char *str, t_meta *pkg);

// prompt.c
char		*get_prompt(void);
// For further parser prototypes, see parser.h

// utils/

// error.c
int			errormsg(char *str,t_meta	*pkg);

// init.c
t_meta		*init_meta(char	**envp);
char		**init_paths(t_meta	*pkg);
t_token		*init_token(t_meta *pkg);

// memory.c
void		free_tokens(t_meta 	*pkg);
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
void		free_str_vector(char **vector);
char		*get_next_word(char *str, t_meta *pkg);

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

void 		update_variable_status_process(t_meta *pkg, int status);

//void		rl_replace_line (const char *text, int clear_undo);
#endif
