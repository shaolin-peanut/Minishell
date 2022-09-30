#include "../../include/minishell.h"

int	process_word(char *str, t_meta *pkg)
{
	char	*word;
	int		len;

	word = NULL;
	len = 0;
	while (is_word(str, pkg->i++))
		len++;
	word = (char *) malloc(sizeof(char) * len + 1);
	word[len] = '\0';
	pkg->i = pkg->i - len - 1;
	len = 0;
	while (is_word(str, pkg->i))
		word[len++] = str[pkg->i++];
	pkg->i--;
	printf("> word: (len:%ld): %s$\n", ft_strlen(word), word);
	printf("> word: i = %d\n", pkg->i);
	word_type_processing(pkg, str, word);
	free(word);
	return (pkg->i);
}
// Next step of the execution is in word_type_processing

//TODO: Complete process_operator()

int	process_operator(char *str,t_meta *pkg)
{
	(void) pkg;
	printf("> operator: %c\n", str[pkg->i]);
	if (str[pkg->i] == '|')
	{
		;
	}
	else if (is_heredoc(str, pkg->i))
	{
		pkg->i += 1;
		//handle_heredoc expansion/lookup
	}
	else if (is_redirection(str, pkg->i))
	{
		;
		//create_redirection_token;
	}
	return (pkg->i);
}

//TODO: Debug process_dollar() in all three situations where it has to work
int	process_dollar(char *str, t_meta *pkg)
{

	printf("> dollar: %s\n", str + pkg->i);
	if (is_var(str, pkg->i))
		(void) pkg;
		//pkg-> = var_substitution();
	if (is_dollar_question(str, pkg->i))
		(void) pkg;
	else if (is_var(str, pkg->i))
		(void) pkg;
	else
		(void) pkg;
	return (pkg->i);
}
