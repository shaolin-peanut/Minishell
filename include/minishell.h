/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/27 16:58:31 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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
t_token	*parser(char *str, t_meta *pkg);
// prompt.c
char	*get_prompt(t_prompt prompt);
// For further parser prototypes, see parser.h

// utils/
// matrix.c
char	**ft_matrixdup(char **matrix);
// error.c
int		errormsg(char *str, t_meta	*pkg);
// init.c
t_meta	*init_meta(t_prompt *prompt);
char	**init_paths(t_meta	*pkg);
t_token	*init_token(t_meta *pkg);
// memory.c
void	free_all(t_meta *pkg);
// list_utils.c
t_token	*return_last_token(t_meta	*pkg);
// executor/

// executor.c
void	executor(t_meta *pkg);

#endif
