/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:06 by sbars             #+#    #+#             */
/*   Updated: 2022/11/09 17:36:00 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_delimiter(t_meta *pkg)
{
	printf("heredoc found at index: %d\n", pkg->i);
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

char	*concatenate_list_to_str(t_builder	*head)
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
		if (current->word[0] == '\n')
			len++;
		else
			len += ft_strlen(current->word);
		current = current->next;
	}
	output = (char *)malloc(sizeof(char) * len + 1);
	// append function. Find end of content, and append.
	ft_strlcpy(output, head->word, len);
	while (head->next != NULL)
	{
		head = head->next;
		if (ft_strlen(head->word) < 1)
			tmp = ft_strjoin(output, "\n");
		else
			tmp = ft_strjoin(output, head->word);
		free(output);
		output = ft_strdup(tmp);
		free(tmp);
	}	
	return (output);
}

char	*capture_content(t_meta *pkg, char *delim)
{
	char		*tmp;
	t_builder	*head;
	t_builder	*last;

	head = init_builder(0, ft_strdup(pkg->str + pkg->i));
	while (1)
	{
		tmp = readline("> ");
		last = add_to_back_of_list(0, head, ft_strdup(tmp));
		free(tmp);
		tmp = ft_strnstr(last->word, delim, ft_strlen(delim));
		if (tmp != pkg->str && tmp != NULL)
		{
			pkg->i += ft_strlen(last->word) - pkg->i;
			return (concatenate_list_to_str(head));
		}
	}	
	return (NULL);
}

void	expand_heredoc(t_meta *pkg)
{
	char		*delim;
	char		*output;

	delim = return_delimiter(pkg);
	if (delim)
		printf("Delimiter found: %s\n", delim);
	else
	{
		printf("delim not found, provide one plz\n");
		return ;
	}
	pkg->i++;
	output = capture_content(pkg, delim);
	create_word_token(output, pkg);
}
