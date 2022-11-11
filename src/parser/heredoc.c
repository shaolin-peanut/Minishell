/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:06 by sbars             #+#    #+#             */
/*   Updated: 2022/11/10 16:22:09 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_delimiter(t_meta *pkg)
{
	//printf("heredoc found at index: %d\n", pkg->i);
	pkg->i += 2;
	while (pkg->str[pkg->i] != '\0')
	{
		if (is_word(pkg->str, pkg->i))
			return (return_word(pkg->str, pkg));
		pkg->i++;
	}
	errormsg("syntax error near unexpected token `newline'", pkg);
	return (NULL);
}

char	*concatenate_list_to_str(t_builder	*head, t_meta *pkg)
{
	char		*output;
	char		*tmp;
	t_builder	*current;
	int			len;

	output = NULL;
	tmp = NULL;
	len = 0;
	current = head;
	while (current != NULL)
	{
		if (current->word != NULL && !ft_strlen(current->word))
			len++;
		else
			len += ft_strlen(current->word);
		current = current->next;
	}
	output = (char *)malloc(sizeof(char) * len + 1);
	output[len] = '\0';
	// append function. Find end of content, and append.
	ft_strlcpy(output, head->word, len);
	while (pkg->str[pkg->i])
		pkg->i++;
	while (head->next->next != NULL)
	{
		head = head->next;
		if (!ft_strlen(head->word))
			tmp = ft_strjoin(output, "\n");
		else
			tmp = ft_strjoin(output, head->word);
		free(output);
		output = ft_strdup(tmp);
		free(tmp);
	}
	free_list(head);
	return (output);
}

char	*capture_content(t_meta *pkg, char *delim)
{
	char		*tmp;
	t_builder	*head;
	t_builder	*last;

	last = NULL;
	head = init_builder(0, ft_strdup(pkg->str + pkg->i));
	while (1)
	{
		tmp = readline("> ");
		last = add_to_back_of_list(0, head, ft_strdup(tmp));
		free(tmp);
		if (ft_strncmp(last->word, delim, ft_strlen(delim)) == 0)
		{
			//pkg->i += ft_strlen(last->word) - pkg->i + 2;
			return (concatenate_list_to_str(head, pkg));
		}
	}	
	return (NULL);
}
// code snippet to print content of list before it's concatenated in one string
//t_builder *a;
//a = head;
//while (a != NULL)
//{
//	printf("capture_content> %s\n", a->word);
	//a = a->next;
//}

// 1. get delimiter and print error if none is found
// 2. 
bool	expand_heredoc(t_meta *pkg)
{
	char		*delim;
	char		*output;

	delim = return_delimiter(pkg);
	if (delim)
		printf("Delimiter found: <%s>\n", delim);
	else
	{
		printf("delim not found, provide one plz\n");
		return (false);
	}
	pkg->i++;
	output = capture_content(pkg, delim);
	if (output)
		create_word_token(output, pkg);
	return (true);
}
