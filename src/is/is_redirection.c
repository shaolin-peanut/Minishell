#include "minishell.h"

bool	have_token_redirection(t_meta *pkg)
{
	t_token *this;

	this = pkg->chain_head;
	if (this)
	{
		while(this)
		{
			if (this->type == TOK_OP)
				return (true);
			this = this->next;
		}
	}
	return (false);
}

bool	is_token_basic_redirection(t_op *this)
{
	if (!this)
		return (false);
	if (this->type == TOK_REDIR_OUT || this->type == TOK_REDIR_IN
		|| this->type == TOK_APPEND_OUT || this->type == TOK_HEREDOC)
		return (true);
	return (false);
}