#include "../include/minishell.h"

void	parser(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}
