/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:19:40 by sbars             #+#    #+#             */
/*   Updated: 2022/11/15 17:33:11 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_meta	*init_meta(char	**envp)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *) malloc(sizeof(t_meta) * 1);
	meta->envp = ft_dup_matrix(envp);
	meta->paths = init_paths(meta);
	meta->str = NULL;
	meta->i = 0;
	meta->chain_head = NULL;
	return (meta);
}

t_last_data	*init_data(void)
{
	t_last_data	*self;

	self = malloc(sizeof(t_last_data));
	self->last_exit_status = 0;
	self->child_pid = 0;
	return (self);
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
		pkg->chain_head = tok;
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
	while (pkg->envp[++i])
	{
		if (ft_strncmp(pkg->envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_split(pkg->envp[i], '=');
			paths = ft_split(tmp[1], ':');
			free_str_vector(tmp);
			if (paths)
				return (paths);
		}
	}
	return (0);
}
