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

int		is_absolute_path(char *word, t_meta *pkg)
{
	int	i;
	
	i = -1;
	(void) pkg;
	if (access(word, X_OK) == 0)
		return (1);
	else
		return (0);
	return (1);
}

char	*is_relative_path(char *word, t_meta *pkg)
{
	char	*current_directory;
	char	*tmp;
	char	*full_path;

	current_directory = getcwd(NULL, 0);
	if (!current_directory)
		return (0);
	tmp = ft_strjoin(current_directory, "/");
	full_path = ft_strjoin(tmp, word);
	free(tmp);
	if (is_absolute_path(full_path, pkg))
		return (full_path);
	else
		return (NULL);
}

char    *is_binary_name(char *word, t_meta *pkg)
{
    int	i;

	i = -1;
	char	*path_and_slash;
	char	*full_path;

	path_and_slash = NULL;
	full_path = NULL;
    
    while (pkg->paths[++i])
	{
		path_and_slash = ft_strjoin(pkg->paths[i], "/");
		full_path = ft_strjoin(path_and_slash, word);
		if (access(full_path, X_OK) == 0)
		{
			free(path_and_slash);
			return (full_path);
		}
		else
		{
			free(path_and_slash);
			free(full_path);
		}
    }
    return (NULL);	
}