/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	prompt(t_meta	*pkg)
{
	char	*line;

	while (1)
	{
		use_signal();
		line = get_line(pkg);
		if (!line)
		{
			ft_putendl_fd("exit", 2);
			break ;
		}
		if (ft_strlen(line) > 0)
			execute_line(pkg, line);
		free(line);
	}
}

char	*get_prompt(t_meta *pkg)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = "[";
	tmp = ft_getenv(pkg, "USER");
	tmp2 = ft_strjoin(str, tmp);
	free(tmp);
	str = ft_strjoin(tmp2, "@minishell: ");
	free(tmp2);
	tmp = ft_getenv(pkg, "PWD");
	tmp2 = ft_strjoin(str, tmp);
	free(tmp);
	free(str);
	str = ft_strjoin(tmp2, "]$ ");
	free(tmp2);
	return (str);
}
