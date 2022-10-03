#include "../../include/minishell.h"

char	*return_word(char *str, t_meta *pkg)
{
	char	*word;
	int		len;

	word = NULL;
	len = 0;
	while (is_word(str, pkg->i + len))
		len++;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	len = 0;
	while (is_word(str, pkg->i))
			word[len++] = str[pkg->i++];
	pkg->i--;
	if (ft_strchr(word, 39) || ft_strchr(word, 34))
		word = process_quotes(word, pkg);
	printf("> word: (len:%ld): %s$\n", ft_strlen(word), word);
	return (word);
}

char	*is_cmd(char *name, t_meta *pkg)
{
	int	i;

	i = -1;
	char	*path_and_slash;
	char	*full_path;

	path_and_slash = NULL;
	full_path = NULL;
	if (pkg->paths == NULL)
		pkg->paths = init_paths(pkg);
	while (pkg->paths[++i])
	{
		path_and_slash = ft_strjoin(pkg->paths[i], "/");
		full_path = ft_strjoin(path_and_slash, name);
		if (access(full_path, X_OK) == 0)
		{
			free(path_and_slash);
			return (full_path);
		}
	}
	return (NULL);
}



//TODO: Debug and complete is_builtin
int	is_builtin(char *word, t_meta *pkg)
{
	(void) pkg;
	/*int i;
	char	*list[8];
	
	i = -1;
	list[0] = "echo";
	list[1] = "cd";
	list[2] = "pwd";
	list[3] = "export";
	list[4] = "unset";
	list[5] = "env";
	list[6] = "exit";
	list[7] = NULL;*/
	if (ft_strncmp(word, "echo", 5) == 0 || ft_strncmp(word, "cd", 3) == 0 
		|| ft_strncmp(word, "pwd", 4) == 0 || ft_strncmp(word, "export", 7 ) == 0
		|| ft_strncmp(word, "unset", 6) == 0 || ft_strncmp(word, "env", 4) == 0 
		|| ft_strncmp(word, "exit", 5) == 0)
		return (1);
	return (0);
}
