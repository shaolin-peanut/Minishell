/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:05 by sbars             #+#    #+#             */
/*   Updated: 2022/11/03 16:18:13 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_name_len(char *str, int index)
{
	int	iterator;
	int	len;

	iterator = index;
	len = 0;
	if (is_dollar(str[index]) && is_word(str, index + 1))
		iterator++;
	while (is_word(str, iterator))
	{
		iterator++;
		len++;
	}
	return (len);
}

// will incremnet index, instead of pkg->i,
// index can be pkg->i, right?
// and it can also be a copy of it, for getting len
char	*return_var_value(char *str, t_meta *pkg, int index)
{
	char	*word;
	char	*value;
	int		len;
	int		i;

	(void) pkg;
	i = 0;
	value = NULL;
	//if (is_dollar(str[index]))
	index++;
	len = var_name_len(str, index);
	word = NULL;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	while (i < len && is_word(str, index))
			word[i++] = str[index++];
	// set env if there's = after the arg name
	//pkg->i--;
	value = getenv(word);
	free(word);
	if (value)
		return (value);
	else
		return (NULL);
}

void	process_variable(t_meta *pkg, char *str, int i)
{
	char	*value;
	// char	*path;

	(void) i;
	value = NULL;
	// path = NULL;
	value = return_var_value(str, pkg, pkg->i);
	pkg->i += ft_strlen(value);
	if (!value)
		return ;
	if (is_word(value, 0))
	{
		process_word(value, pkg);
		//if (is_cmd(value, pkg))
		//	create_cmd_token('', path, pkg);
	}
	//else if (is_operator)
}
