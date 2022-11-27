#include "minishell.h"

void	manage_fd_for_redirection(t_token *token)
{
	t_op *this;

	this = cast_token(token);
	if (is_token_basic_redirection(this))
	{
		manage_fd_basic_redirection(token);
	}
	else if (this->type == pipe_t)
	{
		manage_fd_pipe(token);
	}
	/*
	else if (this->type == heredoc)
	{
		manage_fd_heredoc(token);
	}
	 */
}
/*
void	manage_fd_heredoc(t_token *token)
{
	t_cmd	*prev_cmd;
	t_redir	*redir;
	char	*tmp_file_name;
	int		fd_tmp;

	redir = get_class(token);
	prev_cmd = get_prev_cmd(token);
	tmp_file_name = heredoc_prompt(redir->limiter);
	fd_tmp = open(tmp_file_name, O_RDONLY, 0777);
	redir->tmp_file = init_file(tmp_file_name, fd_tmp);
	if (prev_cmd)
	{
		change_fd_cmd(prev_cmd, fd_tmp, prev_cmd->fd_out);
	}
}
 */

void	manage_fd_pipe(t_token *token)
{
	t_token *prev_cmd;
	t_token	*next_cmd;
	t_op 	*pipe_tok;
	int		fd[2];

	prev_cmd = get_prev_token_cmd(token);
	next_cmd = get_next_token_cmd(token);
	if (!next_cmd || !prev_cmd)
		return ;
	pipe(fd);
	change_fd_cmd(prev_cmd, get_fd_in(prev_cmd), fd[1]);
	// PREV-CMD: fdin: STDIN, fdout: fd[1] (pipe write end)
	change_fd_cmd(next_cmd, fd[0], get_fd_out(next_cmd));
	// NEXT-CMD: fdin: fd[0] (pipe read end), fdout: STDOUT
	pipe_tok = cast_token(token);
	pipe_tok->fd_in = fd[1];
	pipe_tok->fd_out = fd[0];
}

void	manage_fd_basic_redirection(t_token *token)
{
	t_token	*prev_token;
	t_op 	*op;
	//t_cmd	*prev_cmd;
	t_file	*next_file;

	//prev_cmd = get_prev_cmd(token);
	prev_token = get_prev_token_cmd(token);
	next_file = get_next_token_file(token);
	if (!prev_token)
		return ;
	op = cast_token(token);

	if (op->type == redir_in)
	{
		open_next_file_with_flags(op->type, next_file);
		change_fd_cmd(prev_token, next_file->fd, get_fd_out(prev_token));
	}
	else if (op->type == redir_out)
	{
		open_next_file_with_flags(op->type, next_file);
		change_fd_cmd(prev_token, get_fd_in(prev_token), next_file->fd);
	}
	else if (op->type == append_out)
	{
		open_next_file_with_flags(op->type, next_file);
		change_fd_cmd(prev_token, get_fd_in(prev_token), next_file->fd);
	}
	else if (op->type == heredoc)
		;
}

void	open_next_file_with_flags(int type, t_file *file)
{
	if (type == redir_in)
	{
		close(file->fd);
		file->fd = open(file->name, O_RDONLY);
	}
	else if (type == redir_out)
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_TRUNC);
	}
	else if (type == append_out)
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_APPEND);
	}
}
