/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:36:20 by sbars             #+#    #+#             */
/*   Updated: 2022/11/23 13:13:29 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_2d_vector(char **v)
{
	int	i;

	i = -1;
	printf("|> argv{%s", v[++i]);
	while (v[++i] != NULL)
		printf(", %s", v[i]);
	printf("}\n");
}

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
	if (token->type == cmd_t)
		return ((t_cmd *)token->token);
	else if (token->type == builtin_t)
		return ((t_bltn *)token->token);
	else if (token->type == word_t)
		return ((t_word *)token->token);
	else if (token->type == op_t)
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
	int			i;

	i = 0;
	vector = NULL;
	vector = (char **)malloc(sizeof(char *) * (size + 1));
	if (!vector)
		return (NULL);
	while (head)
	{
		vector[i] = NULL;
		vector[i] = ft_strdup(head->word);
		i++;
		head = head->next;
	}
	vector[size] = NULL;
	return (vector);
}
// echo "salut"|echo
// && ++i < size + 1

	// printf("size: %d\n", size);
	// printf("convert_list_to_vector: %p\n", (void *) vector[i]);
