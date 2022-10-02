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
// processing.c
int		process_word(char *str, t_meta *pkg);
int		process_operator(char *str, t_meta *pkg);
int		process_dollar(char *str, t_meta *pkg);
// word_processing.c
char	*return_word(char *str, t_meta *pkg);
void	word_type_processing(t_meta *pkg, char *str, char *word);
int		cmd_check_and_process(char *str, char *word, t_meta *pkg);
int		builtin_check_and_process(char *str, char *word, t_meta *pkg);
// quotes.c
int		closed_quotes_len(char *str, int i);
// create_tokens.c
int		create_cmd_token(char *str, char *full_path, t_meta *pkg);
