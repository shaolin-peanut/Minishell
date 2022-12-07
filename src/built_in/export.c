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

int	export_built_in(t_bltn *bltn, t_meta *pkg)
{
	char	*key;
	int 	i;

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
		if (!key)
		{
			ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
			return (1);
		}
		change_or_create_var(pkg, key, bltn->argv[i]);
		free(key);
		++i;
	}
	return (0);
}

void	change_or_create_var(t_meta *pkg, char *key, char *export_string)
{
	int		i;

	i = ft_matrix_search(pkg->envp, key);
	if (i < 0)
		pkg->envp = ft_extend_matrix(pkg->envp, export_string);
	else if (*(export_string + ft_strlen(key)) && *(export_string + ft_strlen(key)) == '=')
		ft_matrix_replace_elem(pkg->envp, i, export_string);

	if (ft_strncmp(key, "PATH", 4) == 0)
	{
		free_str_vector(pkg->paths);
		pkg->paths = NULL;
		pkg->paths = init_paths(pkg);
	}
}

int	unset(t_bltn *bltn, t_meta *pkg)
{
	char	*key;

	if (bltn->argc < 2)
		return (0);
	key = bltn->argv[1];
	if (ft_strncmp(key, "PATH", 4) == 0)
	{
		free_str_vector(pkg->paths);
		pkg->paths = NULL;
	}
	ft_matrix_del_elem(pkg->envp, key);
	return (0);
}

void	ft_setenv(t_meta *pkg, char *key, char *value)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(key, "=");
	str = ft_strjoin(tmp, value);
	free(tmp);
	change_or_create_var(pkg, key, str);
	free(str);
}

char	*ft_getenv(t_meta *pkg, char *key)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_strcmp("?", key) == 0)
		return (ft_itoa(pkg->last_exit_status));
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
