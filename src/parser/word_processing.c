/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:52 by sbars             #+#    #+#             */
/*   Updated: 2022/11/23 13:10:10 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_slash_dollar(char *str, int i)
{
	return (str[i] == '\\' && is_dollar(str[i + 1]));
}

// LENs the length of the word, including when it is made of one or more quote
// allocates memory for that length, then copies characters from the main string
// to the word string, omitting the quotes and copying the rest
char	*return_word(char *str, t_meta *pkg)
{
	char	*word;
	int		*l_i;
	int		i;

	i = 0;
	l_i = word_len(str, pkg);
	if (!l_i[LEN])
	{
		pkg->i = l_i[ITER] - 1;
		free(l_i);
		return (NULL);
	}
	word = NULL;
	word = ft_calloc((l_i[LEN] + 1), sizeof(char));
	while (i < l_i[LEN] && str[pkg->i])
	{
		if (is_quote(str[pkg->i]))
			i = add_quote_content(word, i, &pkg->i, pkg->str);
		else if (is_slash_dollar(str, pkg->i))
			pkg->i++;
		else if (is_word(str, pkg->i))
			word[i++] = str[pkg->i++];
	}
	pkg->i--;
	free(l_i);
	return (word);
}
// == TESTS
//printf("== RETURN_WORD ==\n")ng word!: %d\n", pkg->i);
//printf("- word len: %d\n", l_i[LEN]);
//printf("- ITER: %d\n", l_i[ITER]);
//printf("- pkg->i before creati

int	*word_len(char *str, t_meta *pkg)
{
	int	*len_iter;

	len_iter = malloc(sizeof(int) * 2);
	len_iter[LEN] = 0;
	len_iter[ITER] = 0;
	len_iter[ITER] = pkg->i;
	while (is_word(str, len_iter[ITER]))
	{
		if (is_quote(str[len_iter[ITER]]) && (str[len_iter[ITER] + 1] != '\0'))
			len_iter = quote_len(pkg->str, len_iter);
		else if (is_slash_dollar(str, len_iter[ITER]))
			len_iter[ITER]++;
		else
			smart_iter(&len_iter[LEN], &len_iter[ITER], 1, 1);
	}
	return (len_iter);
}

// This command does several things
// 1. If paths are not initialized, init them
// 2. Return the full_path to the command if it
// is one, regardless of the type, or NULL if its' not
// 3. If it's an absolute path, 'name' is returned without any other action,
// saving time on the more lengthy checks below
char	*is_cmd(char *name, t_meta *pkg)
{
	char	*path;

	path = NULL;
	if (pkg->paths == NULL)
		pkg->paths = init_paths(pkg);
	if (is_absolute_path(name))
		return (ft_strdup(name));
	path = is_relative_path(name);
	if (path)
		return (path);
	path = is_binary_name(name, pkg);
	if (path)
		return (path);
	else if (access(name, F_OK) == 0)
		return (ft_strdup(name));
	else
		return (NULL);
}

bool	is_builtin(char *word, t_meta *pkg)
{
	(void) pkg;
	if (ft_strncmp(word, "echo", 5) == 0 || ft_strncmp(word, "cd", 3) == 0
		|| ft_strncmp(word, "pwd", 4) == 0 || ft_strncmp(word, "export", 7) == 0
		|| ft_strncmp(word, "unset", 6) == 0 || ft_strncmp(word, "env", 4) == 0
		|| ft_strncmp(word, "exit", 5) == 0)
		return (1);
	return (0);
}
