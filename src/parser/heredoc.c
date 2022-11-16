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
	while (current != NULL)
	{
		if (current->word != NULL && !ft_strlen(current->word))
			len++;
		else
			len += ft_strlen(current->word);
		current = current->next;
	}
	return (len);
}

char	*concatenate_list_to_str(t_builder	*head, t_meta *pkg)
{
	char		*output;
	char		*tmp;
	int			len;

	output = NULL;
	tmp = NULL;
	len = return_concat_str_len(head);
	output = (char *)malloc(sizeof(char) * len + 1);
	output[len] = '\0';
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
			return (concatenate_list_to_str(head, pkg));
	}	
	return (NULL);
}

bool	capture_heredoc(t_meta *pkg)
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
