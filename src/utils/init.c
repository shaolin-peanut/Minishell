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
	meta = (t_meta *) malloc(sizeof(t_meta) * 1);
	meta->prompt = prompt;
	meta->str = NULL;
	meta->i = 0;
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
	tmp = NULL;
	paths = NULL;
	while (pkg->prompt->envp[++i])
	{
		if (ft_strncmp(pkg->prompt->envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_split(pkg->prompt->envp[i], '=');
			paths = ft_split(tmp[1], ':');
			free(tmp);
			if (paths)
				return (paths);
		}
	}
	return (0);
}
