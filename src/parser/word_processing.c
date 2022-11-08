/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:52 by sbars             #+#    #+#             */
/*   Updated: 2022/11/08 16:50:53 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Counts the length of the word, including when it is made of one or more quote
// allocates memory for that length, then copies characters from the main string
// to the word string, omitting the quotes and copying the rest
char	*return_word(char *str, t_meta *pkg)
{
	char	*word;
	int		*c_i;
	int		i;

	i = 0;
	c_i = word_len(str, pkg);
	if (!c_i[COUNT])
	{
		pkg->i = c_i[ITER] - 1;
		return (NULL);
	}
	word = NULL;
	word = (char *) malloc(sizeof(char) * c_i[COUNT] + 1);
	word[c_i[COUNT]] = '\0';
	while (i < c_i[COUNT] && pkg->str[pkg->i])
	{
		if (is_quote(str[pkg->i]))
			i = add_quote_content(word, i, pkg);
		else if (is_word(str, pkg->i))
			word[i++] = str[pkg->i++];
	}
	pkg->i--;
	free(c_i);
	return (word);
}

int	*word_len(char *str, t_meta *pkg)
{
	int	*counter_iterator;

	counter_iterator = (int *) malloc(sizeof(int) * 2);
	counter_iterator[COUNT] = 0;
	counter_iterator[ITER] = 0;
	counter_iterator[ITER] = pkg->i;
	while (is_word(str, counter_iterator[ITER]))
	{
		if (is_quote(str[counter_iterator[ITER]])
			&& (str[counter_iterator[ITER] + 1] != '\0'))
		{
			counter_iterator = quote_len(pkg, counter_iterator);
		}
		else
		{
			counter_iterator[COUNT]++;
			counter_iterator[ITER]++;
		}
	}
	return (counter_iterator);
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
		return (name);
	path = is_relative_path(name);
	if (path)
		return (path);
	free(path);
	path = is_binary_name(name, pkg);
	if (path)
		return (path);
	return (NULL);
}

bool	is_builtin(char *word, t_meta *pkg)
{
	(void) pkg;
	/*char	*list[8];
	
	i = -1;
	list[0] = "echo";
	list[1] = "cd";
	list[2] = "pwd";
	list[3] = "export";
	list[4] = "unset";
	list[5] = "env";
	list[6] = "exit";
	list[7] = NULL;*/
	if (ft_strncmp(word, "echo", 5) == 0 || ft_strncmp(word, "cd", 3) == 0
		|| ft_strncmp(word, "pwd", 4) == 0 || ft_strncmp(word, "export", 7) == 0
		|| ft_strncmp(word, "unset", 6) == 0 || ft_strncmp(word, "env", 4) == 0
		|| ft_strncmp(word, "exit", 5) == 0)
		return (1);
	return (0);
}
