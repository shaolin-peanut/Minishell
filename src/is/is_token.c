#include "minishell.h"

bool	is_standard_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
		return (true);
	return (false);
}

bool	is_token_cmd(t_token *this)
{
	if (!this)
		return (false);
	if (this->type == TOK_BUILTIN || this->type == TOK_CMD)
		return (true);
	return (false);
}