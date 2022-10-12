typedef struct s_meta t_meta;

typedef struct s_lex_node t_lex_node;

struct s_lex_node
{
	t_lex_node	*prev;
	char		*str;
	t_lex_node	*next;
};

// lexical_checks_A.c
int		is_quote(char c);
int		is_dollar(char c);
int		is_var(char *str, int i);
int		is_word(char *str, int i);
// lexical_checks_B.c
int		is_blank(char *str, int i);
int		is_redirection(char *str, int i);
int		is_operator(char *str, int i);
int		is_dollar_question(char *str, int i);
int     is_heredoc(char *str, int i);
// lexical_checks_C.c
char    *is_binary_name(char *word, t_meta *pkg);
char	*is_relative_path(char *word, t_meta *pkg);
int		is_absolute_path(char *path, t_meta *pkg);
// processing.c
void	process_word(char *str, t_meta *pkg);
void	process_operator(char *str, t_meta *pkg);
void	process_dollar(char *str, t_meta *pkg);
// word_processing.c
int		word_len(char *str, t_meta *pkg);
char	*return_word(char *str, t_meta *pkg);
char	*is_cmd(char *name, t_meta *pkg);
int		is_builtin(char *word, t_meta *pkg);
// quotes.c
int		quote_in_word(char *str);
int		add_quote_content(char *word, int i, t_meta *pkg);
int		quote_len(t_meta *pkg, int *counter);
// create_tokens.c
int		create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg);
int		create_builtin_token(char *cmd_name, t_meta *pkg);
int		create_alien_word_token(char *word, t_meta *pkg);
