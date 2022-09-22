/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:02:32 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:19:18 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
int	var_substitution(char *str, int i)
{
	char	*value;
	char	*tmp;

	tmp = ft_substr(str, i, is_var(str, i));
	tmp++;
	value = (char *) malloc(sizeof(char) * ((int) ft_strlen(str + i) - 1));
	value = getenv(tmp);
	if (value)
	{
		printf("var found: %s\n", value);
		return (ft_strlen(value));
	}
	else
	{
		printf(" ");
		return (ft_strlen(tmp));
	}
}

int	cmd_extraction(char *str, int i)
{
	return (is_word(str, i));
}

int	create_builtin_token(char *str, int i)
{
	(void) str;
	return (i + 1);
}

int dollar_question_exec(char *str, int i)
{
	(void) str;
	return (i + 3);
	// last time it worked in bash it returned a 3 digit number, so putting 3 as a placeholder for now
}

int	lone_dollar_sign(char *str, int i)
{
	(void) str;
	(void) i;
	return (1);
}
