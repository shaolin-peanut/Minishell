#include "../../include/minishell.h"

int	process_word(char *str, t_meta *pkg)
{
	char	*word;
	char	*tmp;

	word = NULL;
	word = return_word(str, pkg);
	tmp = is_cmd(word, pkg);
	if (is_builtin(word, pkg))
		create_builtin_token(word, pkg);
	else if (tmp)
		create_cmd_token(word, tmp, pkg);
	else
		create_alien_word_token(word, pkg);	
	free(tmp);
	free(word);
	return (pkg->i);
}
// Next step of the execution is in word_type_processing

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
	else
		(void) pkg;
	return (pkg->i);
}
