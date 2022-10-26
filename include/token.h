/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:04:28 by sbars             #+#    #+#             */
/*   Updated: 2022/10/26 16:06:03 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TOK_NULL 0
# define TOK_WORD 1
# define TOK_QUOTE 2
# define TOK_OP 3
# define TOK_CMD 4
# define TOK_PIPE 5
# define TOK_REDIR_IN 6
# define TOK_REDIR_OUT 7
# define TOK_APPEND_OUT 8
# define TOK_HEREDOC 9
# define TOK_FILE 10

typedef struct s_token	t_token;

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
	char	**cmd_argv;
	int		fd_in;
	int		fd_out;
	int		pid;
}	t_cmd;

typedef struct s_operator
{
	int		type;
	int		fd_in;
	int		fd_out;
}	t_operator;

#endif