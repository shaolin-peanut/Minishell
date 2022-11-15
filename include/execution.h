#ifndef EXECUTION_H
# define EXECUTION_H
# include <fcntl.h>


void	execution(t_meta *pkg);
int		execute_cmd(t_meta *pkg, t_token *token);
int		wait_all_pid(t_meta *pkg);

void	close_all_fd(t_meta *pkg);
void	close_fd_cmd(t_cmd *cmd);
void 	close_fd_bltn(t_bltn *bltn);
void 	close_fd_op(t_op *op);
void	remove_tmp_file(t_token *token_heredoc);

bool	is_standard_fd(int fd);
#endif //EXECUTION_H
