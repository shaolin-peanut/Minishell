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

void	calc_line_len(char *line, int *l_i, t_meta	*pkg)
{
	(void) pkg;
	while (line[l_i[ITER]])
	{
		if (is_var(line, l_i[ITER]))
			l_i = handle_var(l_i, pkg, line);
		else
			smart_iter(&l_i[LEN], &l_i[ITER], 1, 1);
	}
}

int	add_line_var_value(char *source, int i, char	*dest, t_meta *pkg)
{
	char	*value;
	int		value_i;

	value_i = 0;
	value = NULL;
	value = return_var_value(source, pkg, i);
	if (!value)
		return (i);
	while (value[value_i])
		dest[i++] = value[value_i++];
	free(value);
	return (i);
}

char	*expand_variable(char *line, t_meta *pkg)
{
	int		*l_i;
	int		i;
	char	*new_line;

	i = 0;
	l_i = init_int_array(2);
	calc_line_len(line, l_i, pkg);
	new_line = ft_calloc(l_i[LEN] + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	l_i[ITER] = 0;
	while (i < l_i[LEN] && line[l_i[ITER]])
	{
		if (is_var(line, l_i[ITER]))
		{
			i = add_line_var_value(line, i, new_line, pkg);
			l_i[ITER] += var_name_len(line, l_i[ITER]) + 1;
		}
		else
			new_line[i++] = line[l_i[ITER]++];
	}
	free(l_i);
	free(line);
	line = NULL;
	return (new_line);
}
