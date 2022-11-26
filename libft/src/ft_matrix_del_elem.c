#include "../inc/libft.h"

int	ft_matrix_search(char **m, char *key)
{
	char 	*key_f;
	size_t 	key_s;
	int		i;

	i = 0;
	key_s = ft_strlen(key);
	key_f = ft_calloc(sizeof (char), key_s + 2);
	ft_strlcpy(key_f, key, key_s + 1);
	key_f[key_s] = '=';
	while (m[i])
	{
		if (ft_strncmp(m[i], key_f, key_s + 1) == 0)
		{
			free(key_f);
			return (i);
		}
		++i;
	}
	free(key_f);
	return (-1);
}

void ft_matrix_del_elem(char **m, char *key)
{
	char	*next_elem;
	int 	i;

	i = ft_matrix_search(m, key);
	if (i >= 0)
	{
		free(m[i]);
		next_elem = m[i+1];
		while (next_elem)
		{
			next_elem = m[i+1];
			m[i] = next_elem;
			++i;
		}
	}
}

void ft_matrix_replace_elem(char **m, int i, char *elem)
{
	int		j;
	char	*str;

	j = ft_matrixlen(m);
	if (i >=0 && i < j)
	{
		str = ft_strdup(elem);
		if (str)
		{
			free(m[i]);
			m[i] = str;
		}
	}
}

