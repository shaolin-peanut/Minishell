#include "../../include/minishell.h"

void	print_cmd_token(t_token	*tok)
{
	t_cmd	*cmd;

	cmd = cast_token(tok);
	printf("|> TOKEN:CMD\n");
	printf("|> binary_path:%s\n", cmd->binary_path);
	print_2d_vector(cmd->argv);
	printf("|> fd_in:%d\n", cmd->fd_in);
	printf("|> fd_out:%d\n", cmd->fd_out);
}

void	print_operator_tok(t_token	*tok)
{
	t_op	*op;

	op = cast_token(tok);
	printf("|> TOKEN:OPERATOR\n");
	if (op->type == TOK_PIPE)
		printf("|> type: pipe\n");
	if (op->type == TOK_HEREDOC)
		printf("|> type: heredoc\n");
	if (op->type == TOK_REDIR_IN)
		printf("|> type: input redirection\n");
	if (op->type == TOK_REDIR_OUT)
		printf("|> type: output redirection\n");
	printf("|> fd_in:%d\n", op->fd_in);
	printf("|> fd_out:%d\n", op->fd_out);
}

void	print_word(t_token	*tok)
{
	t_word	*w;

	w = cast_token(tok);
	printf("|> TOKEN:WORD\n");
	printf("|> str: %s$\n", w->str);
}

void	print_builtin_token(t_token	*tok)
{
	t_bltn	*b;

	b = cast_token(tok);
	printf("|> TOKEN:BUILTIN\n");
	printf("|> name: %s\n", b->argv[0]);
	print_2d_vector(b->argv);
}

void	print_all_tokens(t_meta	*pkg)
{
	t_token	*token;

	token = pkg->chain_head;
	while (token != NULL)
	{
		printf("---\n");
		if (token->type == TOK_CMD)
			print_cmd_token(token);
		if (token->type == TOK_BUILTIN)
			print_builtin_token(token);
		if (token->type == TOK_OP)
			print_operator_tok(token);
		if (token->type == TOK_WORD)
			print_word(token);
		token = token->next;
	}
}
