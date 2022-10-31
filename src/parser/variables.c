/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:05 by sbars             #+#    #+#             */
/*   Updated: 2022/10/31 16:08:28 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_name_len(char *str, t_meta *pkg)
{
	int	iterator;

	iterator = pkg->i;
	while (is_word(str, iterator))
			iterator++;
	return (iterator);
}

// Counts the length of the word, allocates memory for that length, then copies characters from the main string
// to the word string, omitting the quotes and copying the rest
static char	*return_var_name(char *str, t_meta *pkg)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = var_name_len(str, pkg);
	word = NULL;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	while (i < len && pkg->str[pkg->i])
		if (is_word(str, pkg->i))
			word[i++] = str[pkg->i++];
	pkg->i--;
	return (word);
}

char	*return_var_value(char	*name)
{
	char	*value;

	value = NULL;
	value = getenv(name);
	if (value)
		return (value);
	else
		return (NULL);
}

void	process_variable(t_meta *pkg, char *str, int i)
{
	char	*var_name;
	char	*value;

	(void) i;
	var_name = NULL;
	value = NULL;
	var_name = return_var_name(str, pkg);
	value = return_var_value(var_name);
	if (!value)
		return ;
	if (is_word(value, 0))
	{
		if (is_cmd(value, pkg))
			create_cmd_token(var_name, is_cmd(var_name, pkg), pkg);
	}
}
