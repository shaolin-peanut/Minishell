/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:29:42 by lanlan            #+#    #+#             */
/*   Updated: 2022/11/15 17:32:32 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_home(void)
{
	char	*pwd;
	char	*home;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_strdup("∅ ");
	home = ft_strdup("/Users/lanlan");
	if (home && home[0] && ft_strnstr(pwd, home, ft_strlen(pwd)))
		pwd = ft_strjoin("~", &pwd[ft_strlen(home)]);
	free(home);
	home = ft_strjoin(pwd, " ");
	free(pwd);
	pwd = ft_strjoin(" ", home);
	free(home);
	return (pwd);
}

char	*get_prompt(void)
{
	char	*temp;
	char	*username;
	char	*home;
	char	*prompt_str;

	username = ft_strjoin("guest", "@minishell");
	home = get_home();
	temp = ft_strjoin(home, "$ ");
	prompt_str = ft_strjoin(username, temp);
	free(username);
	free(home);
	free(temp);
	return (prompt_str);
}
