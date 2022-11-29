#include "minishell.h"

void	prompt(t_meta	*pkg)
{
	char	*line;

	while (1)
	{
		use_signal();
		line = get_line();
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strlen(line) > 0)
			execute_line(pkg, line);
		free(line);
	}
}
