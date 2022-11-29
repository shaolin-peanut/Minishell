#include "minishell.h"

void	close_all_fd(t_meta *pkg)
{
	t_token	*token;

	token = pkg->chain_head;
	while (token)
	{
		if (token->type == cmd_t)
			close_fd_cmd((t_cmd *)token->token);
		else if (token->type == builtin_t)
			close_fd_bltn((t_bltn *)token->token);
		else if (token->type == file_t)
			close_fd_file((t_file *)token->token);
//		else if (token->type == op_t)
//			close_fd_op((t_op *)token);
		//else if (token->type == TOK_HEREDOC)
		//	remove_tmp_file(token);
		token = token->next;
	}
}

void 	close_fd_op(t_op *op)
{
	if (!is_standard_fd(op->fd_in))
		close(op->fd_in);
	if (!is_standard_fd(op->fd_out))
		close(op->fd_out);
}

void 	close_fd_bltn(t_bltn *bltn)
{
	//printf("fd closed bltn (%d, %d)\n", bltn->fd_in, bltn->fd_out);
	if (!is_standard_fd(bltn->fd_in))
		close(bltn->fd_in);
	if (!is_standard_fd(bltn->fd_out))
		close(bltn->fd_out);
}

void	close_fd_cmd(t_cmd *cmd)
{
	//printf("fd closed cmd(%d, %d)\n", cmd->fd_in, cmd->fd_out);
	if (!is_standard_fd(cmd->fd_in))
		close(cmd->fd_in);
	if (!is_standard_fd(cmd->fd_out))
		close(cmd->fd_out);
}

void 	close_fd_file(t_file *file)
{
	if (!is_standard_fd(file->fd))
		close(file->fd);
}

/*
void	remove_tmp_file(t_token *token_heredoc)
{
	t_redir	*redir;
	t_file	*tmp_file;

	redir = get_class(token_heredoc);
	tmp_file = redir->tmp_file;
	unlink(tmp_file->name);
	free(tmp_file);
	redir->tmp_file = NULL;
}
*/