/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

bool	have_token_redirection(t_meta *pkg)
{
	t_token	*this;

	this = pkg->chain_head;
	if (this)
	{
		while (this)
		{
			if (this->type == op_t)
				return (true);
			this = this->next;
		}
	}
	return (false);
}

bool	is_token_basic_redirection(t_op *this)
{
	if (!this)
		return (false);
	if (this->type == redir_out || this->type == redir_in
		|| this->type == append_out || this->type == heredoc)
		return (true);
	return (false);
}