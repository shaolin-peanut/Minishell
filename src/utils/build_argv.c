/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:39:34 by sbars             #+#    #+#             */
/*   Updated: 2022/11/03 16:52:03 by sbars            ###   ########.fr       */
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

static char	*get_next_word(char *str, t_meta *pkg)
{
	char		*word;

	if (is_dollar(str[pkg->i]))
	{
		word = return_var_value(str, pkg, pkg->i);
		//pkg->i += ft_strlen(word);
	}
	else
		word = return_word(str, pkg);
	return (word);
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

	b_i = 0;
	head = init_builder(&b_i, name);
	pkg->i++;
	last = head;
	while (pkg->str[pkg->i] != '\0' && !is_operator(pkg->str, pkg->i))
	{
		if (is_word(pkg->str, pkg->i) || is_dollar(pkg->str[pkg->i]))
		{		
			tmp = init_builder(&b_i, get_next_word(pkg->str, pkg));
			last->next = tmp;
			last = tmp;
		}
		pkg->i++;
	}
	pkg->i--;
	argument_vector = convert_list_to_vector(head, last->counter);
	return (argument_vector);
}
