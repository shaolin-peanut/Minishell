/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:29:42 by lanlan            #+#    #+#             */
/*   Updated: 2022/11/11 17:45:40 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_home(t_prompt prompt)
{
	char	*pwd;
	char	*home;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("∅ ");
	home = ft_strdup("/Users/lanlan");
	(void) prompt;
	if (home && home[0] && ft_strnstr(pwd, home, ft_strlen(pwd)))
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
	free(home);
	home = ft_strjoin(pwd, " ");
	free(pwd);
	pwd = ft_strjoin(" ", home);
	free(home);
	return (pwd);
}

char	*get_prompt(t_prompt prompt)
{
	char	*temp;
	char	*username;
	char	*home;
	char	*prompt_str;

	username = ft_strjoin("guest", "@minishell");
	home = get_home(prompt);
	temp = ft_strjoin(home, "$ ");
	prompt_str = ft_strjoin(username, temp);
	free(username);
	free(home);
	free(temp);
	return (prompt_str);
}
