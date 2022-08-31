/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by lanlan            #+#    #+#             */
/*   Updated: 2022/08/27 17:53:30 by lanlan           ###   ########.fr       */
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

// utils/
// matrix.c
char	**ft_matrixdup(char **matrix);
// lexical_checks_A.c
int		is_space_tab(char *str, int i);
int		is_squote(char *str, int i);
int		idquote(char *str, int i);
int		is_dollar_sign(char *str, int i);
int		is_word(char *str, int i);
// extraction.c
int		word_extraction(char *str, int i);
int		var_substitution(char *str, int i);
#endif
