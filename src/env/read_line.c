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

bool	contains_dollar(char *str)
{
	char	*this;

	this = str;
	while (*this)
	{
		if (*this == '$')
			return (true);
		++this;
	}
	return (false);
}

bool	execute_line(t_meta *pkg, char *line)
{
	while (contains_dollar(line))
		line = expand_variable(line, pkg);
	//printf("new line after expand var:%s\n", line);
	if (!line || parser(line, pkg) == false)
		return (false);
//	printf("new line after parser:%s\n", line);
	processing_redirection(pkg);
	print_all_tokens(pkg);
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
