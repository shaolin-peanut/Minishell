/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:33:56 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 15:09:15 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_meta		t_meta;

/*typedef struct s_lex_node	t_lex_node;

struct s_lex_node
{
	t_lex_node	*prev;
	char		*str;
	t_lex_node	*next;
};*/

// basic_char_checks.c
int		is_blank(char *str, int i);
int		is_dollar(char c);
int		is_dollar_question(char *str, int i);
int		is_quote(char c);
// compound_char_checks.c
int		is_word(char *str, int i);
int		is_var(char *str, int i);
// operators_checks.c
int		is_operator(char *str, int i);
int		is_redirection(char *str, int i);
int		is_heredoc(char *str, int i);
int		is_pipe(char c);
// cmd_path_check.c
int		is_absolute_path(char *path);
char	*is_relative_path(char *word);
char	*is_binary_name(char *word, t_meta *pkg);
// processing.c
void	process_word(char *str, t_meta *pkg);
void	process_operator(char *str, t_meta *pkg);
void	process_dollar(char *str, t_meta *pkg);
// word_processing.c
char	*return_word(char *str, t_meta *pkg);
int		word_len(char *str, t_meta *pkg);
char	*is_cmd(char *name, t_meta *pkg);
int		is_builtin(char *word, t_meta *pkg);
// quotes.c
int		quote_in_word(char *str);
int		add_quote_content(char *word, int i, t_meta *pkg);
int		quote_len(t_meta *pkg, int *counter);
// heredoc.c
void	expand_heredoc(t_meta *pkg);
// create_tokens.c
int		create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg);
int		create_builtin_token(char *cmd_name, t_meta *pkg);
int		create_alien_word_token(char *word, t_meta *pkg);

#endif