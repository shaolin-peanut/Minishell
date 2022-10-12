/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_C.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/10/10 14:27:11 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

int		is_absolute_path(char *path, t_meta *pkg)
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

char    *is_binary_name(char *word, t_meta *pkg)
{
    int	i;

	i = -1;
	char	*path_and_slash;
	char	*full_path;
	char	**paths;

	path_and_slash = NULL;
	full_path = NULL; 
	paths = pkg->paths;
    while (*(pkg->paths + ++i))
	{
		path_and_slash = ft_strjoin(paths[i], "/");
		//printf("path_and_slash: %s\n", path_and_slash);
		full_path = ft_strjoin(path_and_slash, word);
		//printf("full_path: %s\n", full_path);
		//free(path_and_slash);
		//path_and_slash = NULL;
		if (is_absolute_path(full_path, pkg))
//		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
		{
			free(full_path);
			full_path = NULL;
		}
    }
    return (NULL);	
}