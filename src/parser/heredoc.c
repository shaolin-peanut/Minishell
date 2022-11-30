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

bool	is_delimiter(char *str, char *delim)
{
	if (ft_strncmp(str, delim, ft_strlen(delim)) == 0 && ft_strlen(str) == ft_strlen(delim))
		return (true);
	return (false);
}

int	return_concat_str_len(t_builder *current, char *delim)
{
	int	len;

	len = 0;
	if (is_delimiter(current->word, delim))
		return (0);
	while (current->next)
	{
		if (current->word != NULL && !ft_strlen(current->word))
			len++;
		else
			len += ft_strlen(current->word) + 1;
		current = current->next;
	}
	return (len);
}

char	*concatenate_list_to_str(t_builder	*head, t_meta *pkg, char *delim)
{
	char		*output;
	int			len;
	t_builder	*tmp;

	(void) pkg;
	output = NULL;
	tmp = head;
	len = return_concat_str_len(head, delim);
	printf("\nlen:%d\n", len);
	output = calloc((len + 1), sizeof(char));
	if (!output)
		return (free_list(head));
	output[len] = '\0';
	if (!len)
	{
		free_list(head);
		return (output);
	}
	ft_strlcat(output, tmp->word, len);
	while (tmp->next && !is_delimiter(tmp->next->word, delim))
	{
		tmp = tmp->next;
		ft_strlcat(output, tmp->word, len);
		ft_strlcat(output, "\n", len);
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
		else if (!is_delimiter(last->word, delim))
			last = add_to_back_of_list(0, last, ft_strdup(tmp));
		free(tmp);
		if (is_delimiter(last->word, delim))
			return (concatenate_list_to_str(head, pkg, delim));
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
	output = capture_content(pkg, delim);
	free(delim);
	if (output)
		create_file_token(output, pkg, heredoc);
	else
		return (false);
	return (true);
}
