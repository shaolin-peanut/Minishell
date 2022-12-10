/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	error_msg_unset(const char *str)
{
	char	*tmp;
	char	*tmp2;

	if(str)
	{
		tmp = ft_strdup("unset: `");
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		tmp = ft_strjoin(tmp2, "': not a valid identifier");
		ft_putendl_fd(tmp, STDERR_FILENO);
		free(tmp);
		free(tmp2);
	}
}

void	error_msg_export(const char *str, char *key)
{
	char	*tmp;
	char	*tmp2;

	if (key)
		free(key);
	if (!str)
		ft_putendl_fd("export: not a valid identifier", STDERR_FILENO);
	else
	{
		tmp = ft_strdup("export: `");
		tmp2 = ft_strjoin(tmp, str);
		free(tmp);
		tmp = ft_strjoin(tmp2, "': not a valid identifier");
		ft_putendl_fd(tmp, STDERR_FILENO);
		free(tmp);
		free(tmp2);
	}
}
