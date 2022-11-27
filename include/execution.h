#ifndef EXECUTION_H
# define EXECUTION_H
# include <fcntl.h>

/*executionfonctions */
void	execution(t_meta *pkg);
int		execute_cmd(t_meta *pkg, t_token *token);
int		wait_all_pid(t_meta *pkg);

void	close_all_fd(t_meta *pkg);
void	close_fd_cmd(t_cmd *cmd);
void 	close_fd_bltn(t_bltn *bltn);
void 	close_fd_op(t_op *op);
void	remove_tmp_file(t_token *token_heredoc);

bool	is_standard_fd(int fd);
bool	is_token_cmd(t_token *this);
bool	cmd_have_standart_fd(t_cmd *cmd);

t_token	*get_first_token_cmd(t_meta *pkg);
t_token	*get_next_token_cmd(t_token *this);
t_token	*get_prev_token_cmd(t_token *this);
t_token	*get_first_token_redirection(t_meta *pkg);
t_token	*get_next_token_redirection(t_token *this);
t_file	*get_next_token_file(t_token *token);
int	get_fd_in(t_token *this);
int	get_fd_out(t_token *this);
char	*get_current_path(void);

char	*get_export_variable_name(char *variable);
char	*get_variable_name(char *variable);
char	*get_env_variable_value(char *variable);

void	change_or_create_var(t_meta *pkg, char *key, char *export_string);
void	ft_setenv(t_meta *pkg, char *key, char *value);
char	*ft_getenv(t_meta *pkg, char *key);

void	bin_execution(t_meta *pkg, t_cmd *cmd);

void	redirect_cmd(t_cmd *cmd);

int	convert_status_process_value(int status);
int	get_last_status(int bin_status, int ret_built_in);

/*redirectionfonctions */

void	processing_redirection(t_meta *pkg);

bool	have_token_redirection(t_meta *pkg);
bool	is_token_basic_redirection(t_op *this);

void	change_fd_cmd(t_token *token, int fd_in, int fd_out);

void	manage_fd_for_redirection(t_token *token);
void	manage_fd_pipe(t_token *token);
void	manage_fd_basic_redirection(t_token *token);
void	open_next_file_with_flags(int type, t_file *file);

void	processing_cmd(t_meta *pkg);

void	processing_built_in(t_meta *pkg);

int	echo(t_bltn *cmd);
int	cd(t_bltn *cmd, t_meta *pkg);
int	env_built_in(t_bltn *bltn, t_meta *pkg);
int	pwd(t_bltn *cmd);
void exit_built_in(t_bltn *bltn, t_meta *pkg);
int	export_built_in(t_bltn *bltn, t_meta *pkg);
int	unset(t_bltn *bltn, t_meta *pkg);

int	built_in_execution(t_meta *pkg, t_bltn *cmd);

void	pass(int key);
void	call_prompt(int key);
void	use_signal(void);

#endif //EXECUTION_H
