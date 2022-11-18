/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:04:28 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 15:18:36 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

// # define TOK_NULL 0
// # define TOK_WORD 1
// # define TOK_FILE 2
// # define TOK_BUILTIN 3
// # define TOK_CMD 4
// # define TOK_OP 55
// # define TOK_PIPE 5
// # define TOK_REDIR_IN 6
// # define TOK_REDIR_OUT 7
// # define TOK_APPEND_OUT 8
// # define TOK_HEREDOC 9

enum e_tok_type	{word_t, builtin_t, cmd_t, op_t};
enum e_op_types	{pipe_t, redir_in, redir_out, append_out, heredoc};
// enum cmd	{binary, builtin}

typedef struct s_token		t_token;
typedef struct s_builder	t_builder;
struct s_builder
{
	int			counter;
	char		*word;
	t_builder	*next;
};

struct s_token
{
	void			*token;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
};

typedef struct s_cmd
{
	char	*binary_path;
	char	**argv;
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_bltn
{
	char	**argv;
	int		fd_in;
	int		fd_out;
}	t_bltn;

typedef struct s_op
{
	int		type;
	int		fd_in;
	int		fd_out;
}	t_op;

typedef struct s_word
{
	int		type;
	char	*str;
}	t_word;
#endif