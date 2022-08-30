#include "../include/minishell.h"

void	parser(char	*str)
{
	int	i;
	int	prev_i;

	i = -1;
	while (str[++i])
	{
		prev_i = i - 1;
		if ((i += is_cmd(str + i)) > prev_i + 1)
		{
			ft_putstr_fd("Command found: ", 1);
			while (++prev_i < i)
				write(1, &str[prev_i], 1);
			write(1, "\n", 1);
		}
	}
}
