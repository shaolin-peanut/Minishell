#include "../../include/minishell.h"

int	process_word(char *str, int i, t_meta *pkg)
{
	char	*word;
	
	word = ft_substr(str, i, is_word(str, i));
	printf("process_word (l:%ld): %s$\n", ft_strlen(word), word);
	if (is_cmd(word, pkg))
		i += cmd_extraction(str, i);
	else if (is_builtin(str, word, pkg))
		i += create_builtin_token(str, i);
	else
		i += ft_strlen(word);
	/*else if (is_file(str, i, pkg))
		check_file_context(str, i);
		OR just store the word in a "word" token to use later when analyzing redirections for example
	*/
	printf("process_word: value of i %d\n---\n", i);
	return (i);
}

int	process_operator(char *str, int i, t_meta *pkg)
{
	(void) pkg;
	printf("operator found %c\n", str[i]);
	if (is_redirection(str, i))
	{
		i++;
		printf("redirection found\n");
	}
	return (i);
}

int	process_dollar(char *str, int i, t_meta *pkg)
{
	(void) pkg;
	printf("dollar being processed: %s\n", str + i);
	if (is_dollar_question(str, i))
		i += dollar_question_exec(str, i);
	else if (is_var(str, i))
		i += var_substitution(str, i);
	else
		i += lone_dollar_sign(str, i);
	return (i);
}
