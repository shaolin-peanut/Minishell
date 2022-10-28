/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:39:34 by sbars             #+#    #+#             */
/*   Updated: 2022/10/28 15:53:13 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str_vector(char **vector)
{
	int	i;

	i = -1;
	while (vector[++i])
		free(vector[i]);
	free(vector);
}

void	print_2d_vector(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i] != NULL)
		printf(">argv[%d]:%s\n", i, argv[i]);
}

t_builder	*init_builder(int *i, char *str)
{
	t_builder	*b;

	b = NULL;
	b = (t_builder *)malloc(sizeof(t_builder) * 1);
	if (!b)
		return (NULL);
	b->counter = ++(*i);
	b->word = NULL;
	b->word = str;
	b->next = NULL;
	printf("builder->counter:%d\nbuilder->word: %s\n", b->counter, b->word);
	return (b);
}
	// Maybe malloc b->next in advance and always loop through on closure?

// What happens in there?
// Create a list of 'builder' structs
// every item contains a counter which tells me how many strings we have
// and all the strings are progressively allocated
// Next, should I just take their pointers or ft_strdup, then free t_builder??
char	**build_argument_vector(char *name, t_meta *pkg)
{
	char		**argument_vector;
	t_builder	*head;
	t_builder	*tmp;
	t_builder	*last;
	int			b_i;

	tmp = NULL;
	b_i = 0;
	head = NULL;
	head = init_builder(&b_i, name);
	printf("head->word: %s\n", head->word);
	last = head;
	while (is_blank(pkg->str, pkg->i) || is_word(pkg->str, pkg->i))
	{
		if (is_word(pkg->str, pkg->i))
		{
			tmp = init_builder(&b_i, return_word(pkg->str, pkg));
			pkg->i++;
			last->next = tmp;
			last = tmp;
		}
		if (is_blank(pkg->str, pkg->i))
			pkg->i++;
	}
	argument_vector = convert_list_to_vector(head, last->counter);
	print_2d_vector(argument_vector);
	free_str_vector(argument_vector);
	return (argument_vector);
}
//free_argv(argument_vector);
