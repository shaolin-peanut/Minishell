/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_tokens(t_meta	*pkg)
{
	t_token	*curr;
	t_token	*prev;

	curr = return_last_token(pkg);
	while (curr)
	{
		prev = curr->prev;
		free_token(curr);
		curr = prev;
	}
	pkg->chain_head = NULL;
}

void	free_all(t_meta *pkg)
{
	if (pkg->paths != NULL)
		free_str_vector(pkg->paths);
	if (pkg->envp)
		free_str_vector(pkg->envp);
	if (pkg->str)
		free(pkg->str);
	free(pkg);
}
