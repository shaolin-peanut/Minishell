/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:33:56 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 16:01:29 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include <stdbool.h>

# define ITER 0
# define LEN 1

typedef struct s_meta		t_meta;
typedef struct s_cmd		t_cmd;

// basic_char_checks.c
bool	is_blank(const char *str, int i);
bool	is_dollar(char c);
bool	is_single_quote(char c);
bool	is_quote(char c);

// compound_char_checks.c
bool	is_word(char *str, int i);
bool	is_var(char *str, int i);
bool	file_check_and_create(t_meta *pkg, int type);

// operators_checks.c
bool	is_operator(char *str, int i);
//  function below uses ints to return which type of redirection is used,
// function is re-used, after chekcing, as paramater for create_token_operator
int		is_redirection(char *str, int i);
bool	is_heredoc(char *str, int i);
bool	is_pipe(char c);

// cmd_path_check.c
bool	is_absolute_path(char *path);
char	*is_relative_path(char *word);
char	*is_binary_name(char *word, t_meta *pkg);

// processing.c
bool	process_word(char *str, t_meta *pkg);
bool	process_operator(char *str, t_meta *pkg);

// variables.c
char	*return_var_value(char *str, int index, t_meta *pkg);
char	*expand_variable(char *line, t_meta *pkg);

// word_processing.c
char	*return_word(char *str, t_meta *pkg);
int		*word_len(char *str, t_meta *pkg);
char	*is_cmd(char *name, t_meta *pkg);
bool	is_builtin(char *word, t_meta *pkg);
bool	is_slash_dollar(char *str, int i);

// quotes.c
void	handle_squote(int *a, int *b, bool *flag);
int		var_name_len(char *str, int index);
int		add_quote_content(char *word, int i, int *iter, char *str);
int		*quote_len(char *str, int *counter);
int		*handle_var(int *l_i, char *str, t_meta *pkg);

// heredoc.c
bool	is_delimiter(char *str, char *delim);
bool	capture_heredoc(t_meta *pkg);

// create_tokens.c
bool	create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg);
bool	create_builtin_token(char *cmd_name, t_meta *pkg);
bool	create_operator_token(t_meta *pkg, int type);
bool	create_file_token(char *str, t_meta *pkg, int type);

// token_init.c
t_cmd	*init_cmd(t_meta	*pkg);
t_op	*init_op(t_meta	*pkg);
t_bltn	*init_builtin(t_meta	*pkg);
t_file	*init_file(t_meta	*pkg);

// parser_utils.c
bool	str_append(char *dst, char *src, int len);
int		*init_int_array(int num);

#endif