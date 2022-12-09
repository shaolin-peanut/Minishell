/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:44 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:41:06 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_squote(int *a, int *b, bool	*flag)
{
	if (*flag == false)
		*flag = true;
	else if (*flag == true)
		*flag = false;
	if (a)
		(*a)++;
	if (b)
		(*b)++;
}

int	*handle_var(int *l_i, char *str, t_meta *pkg)
{
	char	*value;

	value = return_var_value(str, l_i[ITER], pkg);
	if (value)
	{
		l_i[LEN] += (int) ft_strlen(value);
		free(value);
	}
	l_i[ITER] += var_name_len(str, l_i[ITER]) + 1;
	return (l_i);
}

// two purposes:
// 1. get len
// has to be the number of characteres within the quote
// if there are variables, the number of chars of the value of the
// variable must be added to the total LEN returned.
// 2. iterator
// When returning, it must be index + 1 after the closing quote
int	*quote_len(char	*str,	int *l_i)
{
	char	type;

	type = str[l_i[ITER]++];
	while (str[l_i[ITER]] != '\0')
	{
		if (str[l_i[ITER]] == type)
		{
			l_i[ITER]++;
			return (l_i);
		}
		else if (is_slash_dollar(str, l_i[ITER]))
			l_i[ITER]++;
		else
			smart_iter(&l_i[LEN], &l_i[ITER], 1, 1);
	}
	return (l_i);
}

// this function adds to word, the content of the variable, and skips over the
// opening and closing quotes
int	add_quote_content(char *word, int i, int *iter, char *str)
{
	char	type;

	type = str[*iter];
	*iter += 1;
	while (str[*iter] != '\0')
	{
		if (str[*iter] == type)
		{
			*iter += 1;
			return (i);
		}
		else if (is_slash_dollar(str, *iter))
			(*iter)++;
		else
		{
			word[i] = str[*iter];
			smart_iter(&i, iter, 1, 1);
		}
	}
	return (i);
}
