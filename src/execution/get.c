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