#include "minishell.h"

t_token	*get_first_token_cmd(t_meta *pkg)
{
	t_token	*token;

	if (!(pkg->chain_head))
		return (NULL);
	token = pkg->chain_head;
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_cmd(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->next;
	while (this)
	{
		if (is_token_cmd(this))
			return (this);
		this = this->next;
	}
	return (NULL);
}

t_token	*get_prev_token_cmd(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->prev;
	while (this)
	{
		if (is_token_cmd(this))
			return (this);
		this = this->prev;
	}
	return (NULL);
}

t_token	*get_first_token_redirection(t_meta *pkg)
{
	t_token	*token;

	if (!(pkg->chain_head))
		return (NULL);
	token = pkg->chain_head;
	while (token)
	{
		if (token->type == TOK_OP)
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_redirection(t_token *this)
{
	if (!(this))
		return (NULL);
	this = this->next;
	while (this)
	{
		if (this->type == TOK_OP)
			return (this);
		this = this->next;
	}
	return (NULL);
}

t_file	*get_next_token_file(t_token *token)
{
	while (token)
	{
		if (token->type == TOK_FILE)
			return ((t_file *)(token->token));
		token = token->next;
	}
	return (NULL);
}

int	get_fd_in(t_token *this)
{
	t_bltn	*bltn;
	t_cmd	*cmd;
	if(this->type == TOK_BUILTIN)
	{
		bltn = cast_token(this);
		return (bltn->fd_in);
	}
	else if(this->type == TOK_CMD)
	{
		cmd = cast_token(this);
		return (cmd->fd_in);
	}
	return (-42);
}

int	get_fd_out(t_token *this)
{
	t_bltn	*bltn;
	t_cmd	*cmd;
	if(this->type == TOK_BUILTIN)
	{
		bltn = cast_token(this);
		return (bltn->fd_out);
	}
	else if(this->type == TOK_CMD)
	{
		cmd = cast_token(this);
		return (cmd->fd_out);
	}
	return (-42);
}

char	*get_current_path(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		perror("getcwd() Error\n");
	return (path);
}