/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by lanlan            #+#    #+#             */
/*   Updated: 2022/09/02 17:32:26 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_prompt
{
	t_list	*commands;
	char	**envp;
}			t_prompt;

// parsing/
// parser.c
void	parser(char	*str);
// lexical_checks_A.c
int		is_squote(char c);
int		is_dquote(char c);
int		is_dollar(char c);
int		is_var(char **str, int i);
int		is_word(char **str, int i);
// lexical_checks_B.c
// extraction.c
char	*var_substitution(char **str, int i);

// utils/
// matrix.c
char	**ft_matrixdup(char **matrix);
#endif
