/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:44 by sbars             #+#    #+#             */
/*   Updated: 2022/11/03 14:35:19 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_var_value(char	*word, int i, t_meta *pkg)
{
	char	*value;
	int		value_i;
	char	*var_name;

	value = return_var_value(pkg->str, pkg);
	value_i = 0;
	pkg->i++;
	pkg->i += ft_strlen()
	while (value[i] != '\0')
		word[i++] = value[value_i++];
	return (i);
}

int	add_var_len(t_meta 	*pkg, int len)
{
	char	*value;

	value = return_var_value(pkg->str, pkg);
	(void) pkg;
	len += ft_strlen(value);
	printf("add_var_len resulting len: %d", len);
	return (len);
}

// This function makes a copy of pkg->i, and iterates through
// pkg->str until a closing quote is found
int	quote_len(t_meta *pkg, int *iterator)
{
	char	type;
	int		len;

	type = pkg->str[*iterator];
	*iterator += 1;
	len = 0;
	while (pkg->str[*iterator] != '\0')
	{
		if (is_var(pkg->str, *iterator))
			len = add_var_len(pkg, len);
		if (pkg->str[*iterator++] == type)
			return (len);
		else
			len++;
	}
	return (len);
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
		if (is_var(pkg->str, pkg->i))
			i = add_quote_content(word, i, pkg);
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
