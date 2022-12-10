/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#             */
/*   Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

bool	ft_is_valid_key(char *key)
{
	if (!key)
		return (false);
	if (!ft_isalpha(*key))
		return (false);
	++key;
	while (*key)
	{
		if (!ft_isalnum(*key))
			return (false);
		++key;
	}
	return (true);
}

int	export_built_in(t_bltn *bltn, t_meta *pkg)
{
	char	*key;
	int		i;

	if (bltn->argc < 2)
	{
		sort(pkg->envp);
		ft_putmatrix_fd_export(pkg->envp, bltn->fd_out);
		return (0);
	}
	i = 1;
	while (i < bltn->argc)
	{
		key = get_export_variable_name(bltn->argv[i]);
		if (!ft_is_valid_key(key))
			return (error_msg_export(bltn->argv[i], key));
		change_or_create_var(pkg, key, &(bltn->argv[i]));
		free(key);
		++i;
	}
	return (0);
}

void	change_or_create_var(t_meta *pkg, char *key, char **export_string)
{
	int		i;

	if (contains_dollar(*export_string))
		add_escaped_dollar(*&export_string);
	i = ft_matrix_search(pkg->envp, key);
	if (i < 0)
		pkg->envp = ft_extend_matrix(pkg->envp, *export_string);
	else if (*(*export_string + ft_strlen(key))
		&& *(*export_string + ft_strlen(key)) == '=')
		ft_matrix_replace_elem(pkg->envp, i, *export_string);
	if (ft_strncmp(key, "PATH", 4) == 0)
	{
		free_str_vector(pkg->paths);
		pkg->paths = NULL;
		pkg->paths = init_paths(pkg);
	}
}

int	unset(t_bltn *bltn, t_meta *pkg)
{
	int		i;
	char	*key;

	if (bltn->argc < 2)
		return (0);
	i = 1;
	while (i < bltn->argc)
	{
		key = bltn->argv[i];
		if (key && !ft_is_valid_key(key))
			return (error_msg_unset(bltn->argv[i]));
		if (ft_strncmp(key, "PATH", 4) == 0)
		{
			if (pkg->paths)
			{
				free_str_vector(pkg->paths);
				pkg->paths = NULL;
			}
		}
		ft_matrix_del_elem(pkg->envp, key);
		++i;
	}
	return (0);
}
