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
int		is_cmd(char *word, t_meta *pkg);
int		is_builtin(char *str, char *word, t_meta *pkg);
// quotes.c
int		closed_quotes_len(char *str, int i);
