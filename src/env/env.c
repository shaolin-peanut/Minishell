/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_setenv(t_meta *pkg, char *key, char *value)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(key, "=");
	str = ft_strjoin(tmp, value);
	free(tmp);
	change_or_create_var(pkg, key, &str);
	free(str);
}

char	*ft_getenv(t_meta *pkg, char *key)
{
	int		i;
	int		j;
	char	*tmp;
	char	*check;

	if (ft_strcmp("?", key) == 0)
	{
		check = ft_itoa(g_data->last_exit_status);
		return (check);
	}
	j = 0;
	i = ft_matrix_search(pkg->envp, key);
	if (i != -1)
	{
		while ((pkg->envp[i])[j] != '=')
			++j;
		tmp = ft_substr(pkg->envp[i], j + 1, ft_strlen(pkg->envp[i]) - j);
		return (tmp);
	}
	else
		return (NULL);
}
