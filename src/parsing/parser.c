#include "../include/minishell.h"

int		lexical_scan(char	*str, int i)
{
	// identification functions calculate the new index. But the previous index is always saved
	if ((is_word(str, i)))
	{
		// if (is_cmd)
		// 	create_cmd(str + i)
		// if (is_file)
		//  create_file(str + i)
	//	while (++prev_i < i - 1)
	//		write(1, &str[prev_i], 1);
	//	write(1, "\n", 1);
		i += word_extraction(str, i);
	}
	else if (is_dollar_sign(str, i))
	{
		i++;
		if (is_word(str, i))
			i += var_substitution(str, i);
	}
//	else if (i += is_space_tab(str, i) > prev_i)
//		write(1, "..\n", 3);
	//else/* if (is_space_tab(str, i))*/
	//	i++;
	return (i);
}

void	parser(char	*str)
{
	int	i;
	char	*trimmed_str;

	i = -1;
	trimmed_str = ft_strtrim(str, " ");
	while (trimmed_str[++i] != '\0')
		i = lexical_scan(trimmed_str, i);
}
// each iteration of the loop, the check function will 
// sequentially check if any of the types are present, there
// can be more than one item parsed by execution of that function, 
// if there are more than one control path which is entered.
// In any case, i is progressing through the string as it is parsed,
// and the next iteration will land to a new fresh check of the 
// remaining characters	
