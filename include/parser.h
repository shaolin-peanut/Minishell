typedef struct s_meta t_meta;

typedef struct s_lex_node t_lex_node;

struct s_lex_node
{
	t_lex_node	*prev;
	char		*str;
	t_lex_node	*next;
};

#define QUOTES_CLOSED 2
#define CLOSED_AND_UNCLOSED_QUOTES 1
#define UNCLOSED_QUOTES 0

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
int		word_len(char *str, t_meta *pkg);
char	*return_word(char *str, t_meta *pkg);
char	*is_cmd(char *name, t_meta *pkg);
int		is_builtin(char *word, t_meta *pkg);
// quotes.c
int		quotes_unclosed(char c, int a, int b);
char	*process_quotes(char *word, t_meta *pkg);
int		quote_in_word(char *str);
int		iterate_quote_content(t_meta *pkg);
int		add_quote_content(char *word, int i, t_meta *pkg);
int		quote_len(t_meta *pkg, int len);
// create_tokens.c
int		create_cmd_token(char *cmd_name, char *full_path, t_meta *pkg);
int		create_builtin_token(char *cmd_name, t_meta *pkg);
int		create_alien_word_token(char *word, t_meta *pkg);
