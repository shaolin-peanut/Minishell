/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:36:20 by sbars             #+#    #+#             */
/*   Updated: 2022/10/28 15:44:43 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*return_last_token(t_meta	*pkg)
{
	t_token	*last;

	if (!pkg->chain_head)
		return (NULL);
	else
		last = pkg->chain_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

// TODO: complete with all other token types
void	*cast_token(t_token	*token)
{
	if (token->type == TOK_CMD)
		return ((t_cmd *)token->token);
	else if (token->type == TOK_BUILTIN)
		return ((t_builtin *)token->token);	
	else if (token->type == TOK_WORD)
		return ((t_word *)token->token);
	else if (token->type == TOK_OP)
		return ((t_op *)token->token);
	else
		return (NULL);
}

void	free_list(t_builder	*node)
{
	t_builder	*prev;

	prev = NULL;
	while (node != NULL)
	{
		if (prev)
			free(prev);
		free(node->word);
		node = node->next;
		prev = node;
	}
}

char	**convert_list_to_vector(t_builder	*head, int size)
{
	char		**vector;
	t_builder	*current;
	int			i;

	i = -1;
	current = head;
	vector = (char **) malloc(sizeof(char *) * size + 1);
	if (!vector)
		return (NULL);
	vector[size] = NULL;
	while (current != NULL && ++i < size + 1)
	{
		vector[i] = ft_strdup(current->word);
		current = current->next;
	}
	// free_list(head);
	return (vector);
}
