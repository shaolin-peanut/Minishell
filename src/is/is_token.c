#include "minishell.h"

bool	is_standard_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
		return (true);
	return (false);
}