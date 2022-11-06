/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:19:40 by sbars             #+#    #+#             */
/*   Updated: 2022/10/28 13:59:20 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_meta	*init_meta(t_prompt	*prompt)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *) malloc(sizeof(t_meta) * 1);
	meta->prompt = prompt;
	meta->paths = NULL;
	meta->str = NULL;
	meta->i = 0;
	meta->chain_head = NULL;
	return (meta);
}

t_token	*init_token(t_meta *pkg)
{
	t_token	*last;
	t_token	*tok;

	tok = (t_token *) malloc(sizeof(t_token) * 1);
	if (!tok)
		errormsg("malloc err in init_token\n", pkg);
	tok->token = NULL;
	tok->type = 0;
	tok->next = NULL;
	tok->prev = NULL;
	last = return_last_token(pkg);
	if (last)
	{
		last->next = tok;
		tok->prev = last;
	}
	else
	{
		pkg->chain_head = tok;
	}
	return (tok);
}

char	**init_paths(t_meta	*pkg)
{
	int		i;
	char	**tmp;
	char	**paths;

	i = -1;
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
