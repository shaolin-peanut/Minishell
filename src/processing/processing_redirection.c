#include "minishell.h"

void	processing_redirection(t_meta *pkg)
{
	t_token	*token;

	if (have_token_redirection(pkg))
	{
		token = get_first_token_redirection(pkg);
		while (token)
		{
			manage_fd_for_redirection(token);
			token = get_next_token_redirection(token);
		}
		/*
		if (env->verbose == 1)
		{
			ft_printf("=== Processing Redirection ===\n");
			print_all_redirect_info(env);
			ft_printf("-- Command Redirection --\n");
			print_all_cmd_info(env);
			ft_printf("=========\n");
		}
		 */
	}
}

void	change_fd_cmd(t_token *token, int fd_in, int fd_out)
{
	t_bltn	*bltn;
	t_cmd	*cmd;
	if(token->type == TOK_BUILTIN)
	{
		bltn = cast_token(token);
		bltn->fd_in = fd_in;
		bltn->fd_out = fd_out;
	}
	else if(token->type == TOK_CMD)
	{
		cmd = cast_token(token);
		cmd->fd_in = fd_in;
		cmd->fd_out = fd_out;
	}
}

void	redirect_cmd(t_cmd *cmd)
{
	int	fd_in;
	int	fd_out;

	fd_in = cmd->fd_in;
	fd_out = cmd->fd_out;
	if (!is_standard_fd(fd_in))
	{
		dup2(fd_in, STDIN_FILENO);
	}
	if (!is_standard_fd(fd_out))
	{
		dup2(fd_out, STDOUT_FILENO);
	}
}
