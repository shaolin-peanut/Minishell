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
	printf("> word: (len:%ld): %s$\n", ft_strlen(word), word);
	//printf("> word: i = %d\n", pkg->i);
	return (word);
}

void	word_type_processing(t_meta *pkg, char *str, char *word)
{

	if (cmd_check_and_process(str, word, pkg))
	{
		;
	}
	else if (builtin_check_and_process(str, word, pkg))
	{
		;
	}
		//else
	//	ft_strlen(word) - 1;
	//else if (is_builtin(str, word, pkg))
	//	i += create_builtin_token(str, i);
	/*else if (is_file(str, i, pkg))
		check_file_context(str, i);
		OR just store the word in a "word" token to use later when analyzing redirections for example
	*/

}

int	cmd_check_and_process(char *str, char *name, t_meta *pkg)
{
	int	i;

	i = -1;
	char	*path_and_slash;
	char	*full_path;

	(void) str;
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
			create_cmd_token(str, full_path, pkg);
			printf("> Cmd found!: %s\n> binary path: %s\n", name, full_path);
			free(full_path);
			return (1);
		}
	}
	return (0);
}



//TODO: Debug and complete is_builtin
int	builtin_check_and_process(char *str, char *word, t_meta *pkg)
{
	(void) str,
	(void) pkg;
	(void) word;
	/*
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
	return (0);*/
	return (0);
}
