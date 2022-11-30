#include "minishell.h"

bool	is_token_heredoc(t_meta *pkg)
{
	t_token *head;
	t_op 	*op;

	head = pkg->chain_head;
	op = NULL;
	while (head)
	{
		if (head->type == op_t)
		{
			op = cast_token(head);
			if (op->type == heredoc)
				return (true);
		}
		head = head->next;
	}
	return (false);
}

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
	if (this->type == builtin_t || this->type == cmd_t)
		return (true);
	return (false);
}

bool	cmd_have_standart_fd(t_cmd *cmd)
{
	if (is_standard_fd(cmd->fd_in) && is_standard_fd(cmd->fd_out))
		return (true);
	return (false);
}