#include "../include/minishell.h"

void	parser(char	*str)
{
	int	i;

	i = -1;
	while (str[++])
	{
		write(1, &str[++], 1);
	}
}
