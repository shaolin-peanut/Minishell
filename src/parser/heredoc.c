/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:06 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:34:09 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_delimiter(t_meta *pkg)
{
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

int	return_concat_str_len(t_builder *current, char *delim)
{
	int	len;

	len = 0;
	if (is_delimiter(current->word, delim))
		return (0);
	if (!current->next)
		len += (int) ft_strlen(current->word) + 1;
	while (current->next)
	{
		if (current->word != NULL && !ft_strlen(current->word))
			len++;
		else
			len += (int) ft_strlen(current->word) + 1;
		current = current->next;
	}
	return (len);
}

char	*concatenate_list_to_str(t_builder	*head, char *delim)
{
	char		*output;
	int			len;
	t_builder	*tmp;

	output = NULL;
	tmp = head;
	len = return_concat_str_len(head, delim);
	output = calloc((len + 1), sizeof(char));
	if (!output)
		return (free_list(head));
	output[len] = '\0';
	if (!len)
	{
		free_list(head);
		return (output);
	}
	str_append(output, tmp->word, len + 1);
	while (tmp->next && !is_delimiter(tmp->next->word, delim))
	{
		tmp = tmp->next;
		str_append(output, tmp->word, len + 1);
	}
	free_list(head);
	return (output);
}

char	*capture_content(char *delim)
{
	char		*tmp;
	t_builder	*head;
	t_builder	*last;

	last = NULL;
	head = NULL;
	while (1)
	{
		tmp = readline("> ");
		if (!last)
		{
			head = init_builder(0, ft_strdup(tmp));
			last = head;
		}
		else if (!is_delimiter(last->word, delim))
			last = add_to_back_of_list(0, last, ft_strdup(tmp));
		free(tmp);
		if (is_delimiter(last->word, delim))
			return (concatenate_list_to_str(head, delim));
	}
}

bool	capture_heredoc(t_meta *pkg)
{
	char		*delim;
	char		*output;

	output = NULL;
	delim = return_delimiter(pkg);
	if (!delim)
		return (false);
	output = capture_content(delim);
	free(delim);
	if (output)
		create_file_token(output, pkg, heredoc);
	else
		return (false);
	return (true);
}
