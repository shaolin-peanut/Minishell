/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:05 by sbars             #+#    #+#             */
/*   Updated: 2022/11/02 18:10:52 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_name_len(char *str, t_meta *pkg)
{
	int	iterator;
	int	len;

	iterator = pkg->i;
	len = 0;
	while (is_word(str, iterator))
	{
		iterator++;
		len++;
	}
	return (len);
}

// Counts the length of the word, allocates memory for that length, then copies characters from the main string
// to the word string, omitting the quotes and copying the rest
char	*return_var_value(char *str, t_meta *pkg)
{
	char	*word;
	char	*value;
	int		len;
	int		i;

	i = 0;
	value = NULL;
	pkg->i++;
	len = var_name_len(str, pkg);
	word = NULL;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	while (i < len && is_word(str, pkg->i))
			word[i++] = str[pkg->i++];
	// set env if there's = after the arg name
	//pkg->i--;
	value = getenv(word);
	if (value)
		return (value);
	else
		return (NULL);
}

void	process_variable(t_meta *pkg, char *str, int i)
{
	char	*value;
	char	*path;

	(void) i;
	value = NULL;
	path = NULL;
	value = return_var_value(str, pkg);
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
