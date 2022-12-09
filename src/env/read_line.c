/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

size_t	count_dollar(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == '$')
			++count;
		++str;
	}
	return (count);
}

void	add_escaped_dollar(char **str)
{
	char	*tmp;
	char	*this;
	char	*that;

	tmp = ft_calloc(ft_strlen(*str) + count_dollar(*str) + 1, sizeof (char));
	this = tmp;
	that = *str;
	while (*that)
	{
		if (*that == '$')
		{
			*this = '\\';
			++this;
		}
		*this = *that;
		++this;
		++that;
	}
	that = *str;
	*str = tmp;
	free(that);
}

bool	is_expandable(char *str)
{
	char	*this;

	this = str;
	if (*(this - 1) && *(this - 1) == '\\')
		return (false);
	return (true);
}

bool	contains_dollar(char *str)
{
	char	*this;
	bool	is_open_quote;

	this = str;
	is_open_quote = false;
	while (*this)
	{
		if (is_single_quote(*this))
			is_open_quote = !is_open_quote;
		else if (*this == '$' && is_word(this, 1) && !is_quote(*(this + 1)) && !is_open_quote && is_expandable(this))
			return (true);
		++this;
	}
	return (false);
}

bool	execute_line(t_meta *pkg, char *line)
{
	while (contains_dollar(line))
		line = expand_variable(line, pkg);
	if (!line || parser(line, pkg) == false)
		return (false);
	processing_redirection(pkg);
	executor(pkg);
	free_tokens(pkg);
	return (true);
}

char	*get_line(t_meta *pkg)
{
	struct termios	saved;
	struct termios	attributes;
	char			*line;
	char			*p_line;

	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	p_line = get_prompt(pkg);
	line = readline(p_line);
	free(p_line);
	if (!line)
		return (NULL);
	add_history(line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);
}
