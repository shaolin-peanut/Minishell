
#include "minishell.h"

void	execute_line(t_meta *pkg, char *line)
{
	parser(line, pkg);
	processing_redirection(pkg);
	executor(pkg);
	free_tokens(pkg);
}
/*
int	env_have_multi_line(t_env *env)
{
	t_line	*line;
	int		nbr;

	line = get_first_line(env);
	nbr = 1;
	while (line)
	{
		nbr++;
		line = line->next;
	}
	if (nbr > 1)
		return (1);
	return (0);
}

void	execute_multi_line(t_env *env, t_line *line)
{
	while (line)
	{
		execute_line(env, line->content);
		line = line->next;
	}
}

void	parse_line_with_semicolon(t_env *env, char *line)
{
	int		index;
	int		start;
	int		end;
	char	*sub_line;

	index = 0;
	start = index;
	while (line[index])
	{
		if (line[index] == ';' || is_finish(line[index + 1]))
		{
			if (is_finish(line[index + 1]))
				end = index;
			else
				end = index - 1;
			sub_line = malloc_substrcpy(line, start, end);
			add_line_to_env(env, sub_line);
			start = index + 1;
		}
		index++;
	}
}
 */

char	*get_line(t_meta *pkg)
{
	struct termios	saved;
	struct termios	attributes;
	char			*line;
	char 			*p_line;

	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	p_line = get_prompt(pkg);
	line = readline(p_line);
	free(p_line);
	if (!line)
		return (NULL);
	add_history(line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);
}
