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

char	*return_var_value(char *str, int index, t_meta *pkg)
{
	char	*word;
	char	*value;
	int		len;
	int		i;

	i = 0;
	value = NULL;
	len = 0;
	if (is_dollar(str[index]))
		index++;
	while (is_word(str, len + index) && !is_quote(str[len + index]))
		len++;
	word = NULL;
	word = ft_calloc(len + 1, sizeof(char));
	word[len] = '\0';
	while (i < len)
		word[i++] = str[index++];
	value = ft_getenv(pkg, word);
	free(word);
	return (value);
}

int	*calc_line_len(char *line, t_meta *pkg)
{
	int	*array;

	array = init_int_array(2);
	while (line[array[ITER]])
	{
		if (is_var(line, array[ITER]))
			array = handle_var(array, line, pkg);
		else
			smart_iter(&array[LEN], &array[ITER], 1, 1);
	}
	return (array);
}

int	add_line_var_value(char **lines, int i, int *iter, t_meta *pkg)
{
	char	*value;
	int		value_i;

    printf("add_line_var_value triggered\n");
	value_i = 0;
	value = NULL;
	value = return_var_value(lines[0], *iter, pkg);
	*iter += var_name_len(lines[0], *iter) + 1;
	if (!value)
		return (i);
	while (value[value_i])
		lines[1][i++] = value[value_i++];
	free(value);
	return (i);
}

//		printf("> line[%d]: %c\n", l_i[ITER], line[l_i[ITER]]);
//		printf("> new_line[%d]: %c\n", i, new_line[i]);
//printf("line w/ expand vars len: %d\n", l_i[LEN]);

char	*expand_variable(char *line, t_meta *pkg)
{
	int		*l_i;
	int		i;
	char	*new_line[2];
	bool	is_open_quote;

	i = 0;
	is_open_quote = false;
	l_i = calc_line_len(line, pkg);
	new_line[1] = ft_calloc(l_i[LEN] + 1, sizeof(char));
    new_line[1][l_i[LEN]] = '\0';
	new_line[0] = line;
	if (!new_line[1])
		return (NULL);
	l_i[ITER] = 0;
	while (i < l_i[LEN] && line[l_i[ITER]])
	{
		if (is_single_quote(line[l_i[ITER]]))
			handle_squote(&l_i[ITER], &i, &is_open_quote);
		else if (is_var(line, l_i[ITER]) && !is_open_quote)
			i = add_line_var_value(new_line, i, &l_i[ITER], pkg);
		else
			new_line[1][i++] = line[l_i[ITER]++];
	}
	free(l_i);
	free(line);
	line = NULL;
	return (new_line[1]);
}
