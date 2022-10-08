#include "../../include/minishell.h"

// This function should figure out the length of the word, including any scenario of words with quotes.
int	word_len(char *str, t_meta *pkg)
{
	int	len;
	int	qc;
	
	len = 0;
	qc = 0;
	while (is_word(str, pkg->i + len)/* || (quotes_unclosed(str[pkg->i], sc, dc))*/)
	{
		if (is_quote(str[pkg->i + len]) && str[pkg->i + len + 1] != '\0')
		{
			qc++;
			len = quote_len(pkg, len);
			//printf("quote length: %d\n", len);
		}
		else 
		{
			len++;
		}
	}
	return (len - qc);
}

// What should return_word do?
// 1. Capture entire words and stop at delimiters like blanks and operators
// 2. Identify quotes, extract the content of them, and concatenate with the rest
// 3. Correctly allocate memory for, and fill in, the 'word' variable
char	*return_word(char *str, t_meta *pkg)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	word = NULL;
	len = word_len(str, pkg);
	printf("> len of word: %d\n", len);
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	//while (is_word(str, pkg->i) || quotes_unclosed(str[pkg->i], sc, dc))
	while (i < len)
	{ 
		if (is_quote(str[pkg->i]))
			i = add_quote_content(word, i, pkg);
		else
		{
			word[i++] = str[pkg->i++];
			printf("|| word[%d] now: %c ||\n", i - 1, str[pkg->i - 1]);
		}
	}
	pkg->i--;
	//while (quote_in_word(word))
	//	word = process_quotes(word, pkg);
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
