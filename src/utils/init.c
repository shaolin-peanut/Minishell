/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:19:40 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:21:25 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_meta	*init_meta(t_prompt	*prompt)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *) malloc(sizeof(meta) * 1);
	meta->prompt = prompt;
	return (meta);
}


char	**init_paths(t_meta	*pkg)
{
	int	i;
	char	**tmp;
	char	**paths;
	char	**e;

	i = -1;
	e = pkg->prompt->envp;
// This actually is the paths_finder command, something else that should be done before... Or maybe only done when at least one command is found. If pkg->paths is null, run paths_finder.
	while (e[++i])
	{
		// if the first five characters of i line of envp starts with PATH=, it's the right one
		if (ft_strncmp(e[i], "PATH=", 5))
		{
			printf("PATHS FOUND: %s", e[i]);
			tmp = ft_split(e[i], '=');
			printf("splitted: %s", tmp[1]);
			paths = ft_split(tmp[1], ':');
			free(tmp);
			return (paths);
		}
	}
	return (0);
}
