/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_token	*get_first_token_cmd(t_meta *pkg)
{
	t_token	*token;

	if (!(pkg->chain_head))
		return (NULL);
	token = pkg->chain_head;
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_cmd(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->next;
	while (this)
	{
		if (is_token_cmd(this))
			return (this);
		this = this->next;
	}
	return (NULL);
}

t_token	*get_prev_token_cmd(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->prev;
	while (this)
	{
		if (is_token_cmd(this))
			return (this);
		this = this->prev;
	}
	return (NULL);
}

t_token	*get_first_token_redirection(t_meta *pkg)
{
	t_token	*token;

	if (!(pkg->chain_head))
		return (NULL);
	token = pkg->chain_head;
	while (token)
	{
		if (token->type == op_t)
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_redirection(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->next;
	while (this)
	{
		if (this->type == op_t)
			return (this);
		this = this->next;
	}
	return (NULL);
}
