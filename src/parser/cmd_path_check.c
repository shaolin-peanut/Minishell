/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_C.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 12:19:08 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_absolute_path(char *path, t_meta *pkg)
{
	(void) pkg;
	if (access(path, X_OK) == 0)
		return (1);
	else
		return (0);
	return (1);
}

char	*is_relative_path(char *word, t_meta *pkg)
{
	char	*current_directory;
	char	*path_and_slash;
	char	*full_path;

	current_directory = getcwd(NULL, 0);
	if (!current_directory)
		return (0);
	path_and_slash = ft_strjoin(current_directory, "/");
	full_path = ft_strjoin(path_and_slash, word);
	free(path_and_slash);
	if (is_absolute_path(full_path, pkg))
		return (full_path);
	else
	{
		free(full_path);
		return (NULL);
	}
}

char	*is_binary_name(char *word, t_meta *pkg)
{
	int		i;
	char	*path_and_slash;
	char	*full_path;
	char	**paths;

	i = -1;
	path_and_slash = NULL;
	full_path = NULL;
	paths = pkg->paths;
	while (*(pkg->paths + ++i))
	{
		path_and_slash = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path_and_slash, word);
		if (is_absolute_path(full_path, pkg))
			return (full_path);
		else
		{
			free(full_path);
			full_path = NULL;
		}
	}
	return (NULL);
}
