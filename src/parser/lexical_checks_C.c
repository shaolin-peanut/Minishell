#include "../../include/minishell.h"

int	is_cmd(char	*str, char *name, t_meta *pkg)
{
	int	i;

	i = -1;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	(void) str;
	if (pkg->paths == NULL)
		pkg->paths = init_paths(pkg);
	while (pkg->paths[++i])
	{
		tmp = ft_strjoin(pkg->paths[i], "/");
		tmp2 = ft_strjoin(tmp, name);
		if (access(tmp2, X_OK) == 0)
		{
			printf("Cmd found!: %s\nbinary path: %s", name, tmp2);
			free(tmp);
			free(tmp2);
			return (1);
		}
	}
	return (0);
}

int	is_builtin(char *str, char *word, t_meta *pkg)
{
	int i;
	char	*list[8];
	
	i = -1;
	list[0] = "echo";
	list[1] = "cd";
	list[2] = "pwd";
	list[3] = "export";
	list[4] = "unset";
	list[5] = "env";
	list[6] = "exit";
	list[7] = NULL;
	while (list[++i] != NULL)
	{
		if (ft_strncmp(list[i], word, ft_strlen(list[i])))
			return (1);
	}

	(void) word;
	(void) str;
	(void) pkg;
	return (0);
}

