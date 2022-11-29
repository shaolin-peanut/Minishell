#include "minishell.h"

int	export_built_in(t_bltn *bltn, t_meta *pkg)
{
	char	*key;

	if (bltn->argc < 2)
	{
		sort(pkg->envp);
		ft_putmatrix_fd_export(pkg->envp, 1, bltn->fd_out);
		return (0);
	}
	key = get_export_variable_name(bltn->argv[1]);
	if (!key)
	{
		ft_putstr_fd("export: not a valid identifier\n", 1);
		return (1);
	}
	change_or_create_var(pkg, key, bltn->argv[1]);
	free(key);
	return (0);
}

void	change_or_create_var(t_meta *pkg, char *key, char *export_string)
{
	int		i;

	i = ft_matrix_search(pkg->envp, key);
	if (i >= 0)
		ft_matrix_replace_elem(pkg->envp, i, export_string);
	else
		pkg->envp = ft_extend_matrix(pkg->envp, export_string);
}

int	unset(t_bltn *bltn, t_meta *pkg)
{
	char	*key;

	if (bltn->argc < 2)
		return (0);
	key = bltn->argv[1];
	ft_matrix_del_elem(pkg->envp, key);
	return (0);
}

void	ft_setenv(t_meta *pkg, char *key, char *value)
{
	char *tmp;
	char *str;

	tmp = ft_strjoin(key, "=");
	str = ft_strjoin(tmp, value);
	free(tmp);
	change_or_create_var(pkg, key, str);
	free(str);
}

char *ft_getenv(t_meta *pkg, char *key)
{
	int	i;
	int j;
	char *tmp;
	j = 0;
	i = ft_matrix_search(pkg->envp, key);
	if (i != -1)
	{
		while((pkg->envp[i])[j] != '=')
			++j;
		//peut =etre j + 1 ??
		tmp = ft_substr(pkg->envp[i], j + 1, ft_strlen(pkg->envp[i]) - j);
		return (tmp);
	}
	else
		return (NULL);
}