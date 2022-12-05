/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:59:05 by sbars             #+#    #+#             */
/*   Updated: 2022/11/18 16:27:43 by sbars            ###   ########.fr       */
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
	return (len);
}

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
	while (is_word(str, len + index) && !is_quote(str[len + index]))
		len++;
	word = NULL;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	while (i < len)
			word[i++] = str[index++];
	value = ft_getenv(pkg, word);
	free(word);
	return (value);
}

void	process_variable(t_meta *pkg, char *str, int i)
{
	char	*value;
	char	*path;

	(void) i;
	value = NULL;
	path = NULL;
	value = return_var_value(str, pkg, i);
	pkg->i += var_name_len(str, i);
	if (!value || ft_strlen(value) < 2)
		return ;
	if (is_word(value, 0))
	{
		path = is_cmd(value, pkg);
		if (path)
			create_cmd_token(value, path, pkg);
		else
		{
			print_cmd_not_found(value);
			free(value);
		}
	}
}
