/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:12:06 by sbars             #+#    #+#             */
/*   Updated: 2022/10/26 13:16:49 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_heredoc_output(t_meta *pkg)
{
	(void) pkg;
}

// finds the delimiter and increments until
// the char jsut after the delimiter char	
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

int	is_heredoc_end(t_meta *pkg, char *delimiter)
{
	int	i;
	int	j;

	if (ft_strncmp((pkg->str + pkg->i), delimiter, ft_strlen(delimiter)) == 0)
		return (1);
	else
		return (0);
	if (delimiter[0] == pkg->str[pkg->i])
		return (0);
	i = pkg->i;
	j = 0;
	while (delimiter[j] != '\0')
	{
		if (pkg->str[i] != delimiter[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*prompt_and_return(t_meta *pkg, char *output, char *delimiter)
{
	int		i;
	char	*new_str;
	char	*temp;

	if (!output)
		output = ft_strdup("");
	while (1)
	{
		i = -1;
		temp = readline(">");
		new_str = ft_strjoin(output, temp);
		free(output);
		output = ft_strdup(new_str);
		free(new_str);
		while (temp[++i])
		{
			if (is_heredoc_end(pkg, delimiter))
			{
				output = ft_strjoin(output, temp);
				return (output);
			}
		}
		free(temp);
	}
	return (output);
}

// PURPOSE:
// 1. Create a token with the content of the heredoc, if there are
// two delimiters.
// 2. Open a new prompt if the given line doesn't have the closing delimiter
// repeat this until a delimiter is found and concatenate all inputs until stop
// 3. Increment pkg->i until the last character of the closing delimiter, so
// that parsing can continue if there are subsequent items to parse
void	expand_heredoc(t_meta *pkg)
{
	char	*delimiter;
	char	*output;
	int		i_backup;

	delimiter = return_delimiter(pkg);
	printf("delimiter: %s(%ld)\npkg->i: %d\n", delimiter, ft_strlen(delimiter), pkg->i);
	pkg->i++;
	i_backup = pkg->i;
	while (pkg->str[pkg->i] != '\0')
	{
		if (pkg->str[pkg->i + 1] == '\0')
		{
			output = prompt_and_return(pkg, output, delimiter);
			create_heredoc_output(pkg);
		}
		if (is_heredoc_end(pkg, delimiter))
		{
			ft_substr(pkg->str, i_backup, pkg->i - i_backup);
			create_heredoc_output(pkg);
			pkg->i += ft_strlen(delimiter);
			break ;
		}
		pkg->i++;
	}
}
