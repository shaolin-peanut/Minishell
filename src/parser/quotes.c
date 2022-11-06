/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:44 by sbars             #+#    #+#             */
/*   Updated: 2022/11/03 16:50:40 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_var_value(char	*word, int i, t_meta *pkg)
{
	char	*value;
	int		value_i;

	value_i = 0;
	printf("STR[%d]: %c", pkg->i, pkg->str[pkg->i]);
	value = NULL;
	value = return_var_value(pkg->str, pkg, pkg->i);
	if (!value)
	{
		printf("errror\n");
		return (++i);
	}
	while (value[value_i] && word[i])
		word[i++] = value[value_i++];
	// i--;
	return (i);
}

int	add_var_len(t_meta *pkg, int len, int iter)
{
	char	*value;
	int		copy;

	copy = iter;
	value = NULL;
	value = return_var_value(pkg->str, pkg, copy);
	if (value)
		len += ft_strlen(value);
	else
	{
		printf("no value returned\n");
		len++;
	}
	printf("add_var_len resulting len: %d\n", len);
	return (len);
}

// two purposes:
// 1. counter
// has to be the number of characteres within the quote
// if there are variables, the number of chars of the value of the
// variable must be added to the total count returned.
// 2. iterator
// When returning, it must be index + 1 after the closing quote
int	*quote_len(t_meta *pkg, int *c_i)
{
	char	type;
	char	*value;

	type = pkg->str[c_i[ITER]];
	c_i[ITER]++;
	while (pkg->str[c_i[ITER]] != '\0')
	{
		if (type == 34 && is_var(pkg->str, c_i[ITER]))
		{
			// the length of the output word is incremented by
			// the number of characters of the var value
			value = return_var_value(pkg->str, pkg, c_i[ITER]);
			if (value)
				c_i[COUNT] = ft_strlen(value);
			// the iterator itself, is incremented by the number of characters
			// of the variable name, plus 1 for the dollar
			// c_i[ITER] += var_name_len(pkg->str, c_i[ITER]) + 1;
		}
		if (pkg->str[c_i[ITER]] == type)
		{
			c_i[ITER]++;
			printf ("quote_len:\n-len: %d\n-iterator: %d\n-str[i]:%c\n", c_i[COUNT], c_i[ITER], pkg->str[c_i[ITER]]);
			return (c_i);
		}
		else
		{
			c_i[COUNT]++;
			c_i[ITER]++;
		}
		printf ("quote_len:\n-len: %d\n-iterator: %d\n-str[iter - 1]:%c\n", c_i[COUNT], c_i[ITER], pkg->str[c_i[ITER] - 1]);
	}
	return (c_i);
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
			i++;
			pkg->i++;
		}
	}
	return (i);
}

int	quote_in_word(char *word)
{
	return (ft_strchr(word, 39) || ft_strchr(word, 34));
}
