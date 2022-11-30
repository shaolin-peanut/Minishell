/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:06 by sbars             #+#    #+#             */
/*   Updated: 2022/11/11 17:37:43 by sbars            ###   ########.fr       */
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

int	return_concat_str_len(t_builder *current)
{
	int	len;

	len = 0;
	while (current)
	{
		if (!current->word)
			break ;
		if (current->word != NULL && !ft_strlen(current->word))
			len++;
		else
			len += ft_strlen(current->word) + 1;
		current = current->next;
	}
	return (len);
}

char	*concatenate_list_to_str(t_builder	*head, t_meta *pkg)
{
	char		*output;
	int			len;

	(void) pkg;
	output = NULL;
	len = return_concat_str_len(head);
	output = ft_calloc(sizeof(char), len + 1);
	//output = (char *)malloc(sizeof(char) * (len + 1));
	output[len] = '\0';
	ft_strlcat(output, head->word, len + 1);
	while (head->next->next != NULL)
	{
		head = head->next;
		if (ft_strlen(head->word))
			ft_strlcat(output, head->word, len + 1);
		ft_strlcat(output, "\n", len + 1);
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
	head = NULL;
	while (1)
	{
		tmp = readline("> ");
		if (!last)
		{
			head = init_builder(0, ft_strdup(tmp));
			last = head;
		}
		else
			last = add_to_back_of_list(0, last, ft_strdup(tmp));
		free(tmp);
		if (ft_strncmp(last->word, delim, ft_strlen(delim)) == 0)
			return (concatenate_list_to_str(head, pkg));
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
	pkg->i++;
	output = capture_content(pkg, delim);
	free(delim);
	if (output)
		create_file_token(output, pkg, heredoc);
	return (true);
}
