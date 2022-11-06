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
	int	len;

	len = 0;
	if (is_dollar(str[index]))
		index++;
	while (is_word(str, len + index) && !is_quote(str[len + index]))
		len++;
	printf("var_name_len:%d\n", len);
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
	len = 0;
	if (is_dollar(str[index]))
		index++;
	while (is_word(str, len + index))
		len++;
	word = NULL;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	while (i < len && is_word(str, index) && !is_quote(str[index]))
			word[i++] = str[index++];
	// set env if there's = after the arg name
	printf("return_var_value var name:%s$\n", word);
	index--;
	//pkg->i--;
	value = getenv(word);
	free(word);
	return (value);
}

void	process_variable(t_meta *pkg, char *str, int i)
{
	char	*value;

	(void) i;
	value = NULL;
	value = return_var_value(str, pkg, pkg->i);
	pkg->i += var_name_len(str, i);
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
