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

int	add_var_value(char	*word, int i, t_meta *pkg)
{
	char	*value;
	int		value_i;

	value_i = 0;
	value = NULL;
	value = return_var_value(pkg->str, pkg, pkg->i);
	if (!value)
		return (i);
	while (value[value_i])
		word[i++] = value[value_i++];
	free(value);
	return (i);
}
	//printf("STR[%d]: %c", pkg->i, pkg->str[pkg->i]);

//int	add_var_len(t_meta *pkg, int len, int iter)
//{
//	char	*value;
//	int		copy;
//
//	copy = iter;
//	value = NULL;
//	value = return_var_value(pkg->str, pkg, copy);
//	if (value)
//		len += ft_strlen(value);
//	else
//		printf("no value returned\n");
//	printf("add_var_len resulting len: %d\n", len);
//	return (len);
//}

int	*handle_var(int *l_i, t_meta *pkg, char *str)
{
	char	*value;

	value = return_var_value(str, pkg, l_i[ITER]);
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
int	*quote_len(t_meta *pkg, int *l_i)
{
	char	type;

	type = pkg->str[l_i[ITER]++];
	while (pkg->str[l_i[ITER]] != '\0')
	{
		if (type == 34 && is_var(pkg->str, l_i[ITER]))
			l_i = handle_var(l_i, pkg, pkg->str);
		if (pkg->str[l_i[ITER]] == type)
		{
//			if (value != NULL)
//				free(value);
			l_i[ITER]++;
			return (l_i);
		}
		else
			smart_iter(&l_i[LEN], &l_i[ITER], 1, 1);
	}
//	if (value)
//		free(value);
	return (l_i);
}

// this function adds to word, the content of the variable, and skips over the
// opening and closing quotes
int	add_quote_content(char *word, int i, t_meta *pkg)
{
	int	type;

	type = pkg->str[pkg->i];
	pkg->i++;
	while (pkg->str[pkg->i] != '\0')
	{
		if (type == 34 && is_var(pkg->str, pkg->i))
		{
			i = add_var_value(word, i, pkg);
			pkg->i += var_name_len(pkg->str, pkg->i) + 1;
		}
		if (pkg->str[pkg->i] == type)
		{
			pkg->i++;
			return (i);
		}
		else
		{
			word[i] = pkg->str[pkg->i];
			smart_iter(&i, &pkg->i, 1, 1);
		}
	}
	return (i);
}

int	quote_in_word(char *word)
{
	return (ft_strchr(word, 39) || ft_strchr(word, 34));
}
