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
	printf("|> argv{%s", argv[++i]);
	while (argv[++i] != NULL)
		printf(", %s", argv[i]);
	printf("}\n");
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
	return (b);
}

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
	char		*s;

	s = pkg->str;
	tmp = NULL;
	b_i = 0;
	head = NULL;
	head = init_builder(&b_i, name);
	pkg->i++;
	last = head;
	while (is_blank(s, pkg->i) || is_dollar(s[pkg->i]) || is_word(s, pkg->i))
	{
		if (is_word(s, pkg->i))
		{
			tmp = init_builder(&b_i, return_word(pkg->str, pkg));
			last->next = tmp;
			last = tmp;
		}
		pkg->i++;
	}
	pkg->i--;
	argument_vector = convert_list_to_vector(head, last->counter);
	// print_2d_vector(argument_vector);
	// free_str_vector(argument_vector);
	// free stuff not here, in program termination functions, or from errormsg
	return (argument_vector);
}
