/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:39:34 by sbars             #+#    #+#             */
/*   Updated: 2022/11/23 13:14:23 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_vector(char **vector)
{
	int		i;
	char	*tmp;

	i = 0;
	while (vector[i] != 0)
	{
		tmp = vector[i];
		free(tmp);
		i++;
	}
	tmp = vector[i];
	free(tmp);
	free(vector);
}

t_builder	*init_builder(int *i, char *str)
{
	t_builder	*b;

	b = NULL;
	if (!str)
		return (NULL);
	b = (t_builder *)malloc(sizeof(t_builder) * 1);
	if (!b)
		return (NULL);
	if (i)
		b->counter = ++(*i);
	else
		b->counter = 0;
	b->word = NULL;
	b->word = str;
	b->next = NULL;
	return (b);
}

static char	*get_next_word(char *str, t_meta *pkg)
{
	char		*word;

	word = NULL;
	if (is_dollar(str[pkg->i]))
	{
		printf("is dollar\n");
		word = return_var_value(str, pkg, pkg->i);
		pkg->i += var_name_len(str, pkg->i);
	}
	else
	{
		word = return_word(str, pkg);
	}
	return (word);
}

t_builder	*add_to_back_of_list(int *counter, t_builder *head, char *word)
{
	t_builder	*last;

	last = head;
	while (last->next != NULL)
		last = last->next;
	last->next = init_builder(counter, word);
	last = last->next;
	return (last);
}

// What happens in there?
// Create a list of 'builder' structs
// every item contains a counter which tells me how many strings we have
// and all the strings are progressively allocated
char	**build_argument_vector(char *name, t_meta *pkg)
{
	char		**argument_vector;
	char		*word;
	t_builder	*head;
	t_builder	*last;
	int			b_i;

	b_i = 0;
	head = init_builder(&b_i, name);
	last = head;
	pkg->i++;
	while (pkg->str[pkg->i] != '\0' && !is_operator(pkg->str, pkg->i))
	{
		if (is_word(pkg->str, pkg->i) || is_dollar(pkg->str[pkg->i]))
		{
			word = get_next_word(pkg->str, pkg);
			if (word)
				add_to_back_of_list(&b_i, head, word);
		}
		pkg->i++;
	}
	pkg->i--;
	while (last->next != NULL)
		last = last->next;
	argument_vector = convert_list_to_vector(head, last->counter);
	return (argument_vector);
}

/*
echo "$user"|cat -e     === takes

*/