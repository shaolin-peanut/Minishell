/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:50 by sbars             #+#    #+#             */
/*   Updated: 2022/12/02 15:30:03 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	smart_iter(int *a, int *b, int incr_a, int incr_b)
{
	if (a && incr_a)
		*a += incr_a;
	if (b && incr_b)
		*b += incr_b;
}

void	print_file_token(t_token *tok)
{
	t_file	*file;

	file = cast_token(tok);
	printf("|> TOKEN:FILE\n");
	printf("|> name: %s\n", file->name);
	printf("|> fd: %d\n", file->fd);
}

bool	is_delimiter(char *str, char *delim)
{
	size_t	delim_len;

	delim_len = ft_strlen(delim);
	if (ft_strncmp(str, delim, delim_len) == 0 && (ft_strlen(str) == delim_len))
		return (true);
	return (false);
}

bool	str_append(char *dst, char *src, int len)
{
	size_t	l;

	l = len;
	ft_strlcat(dst, src, l);
	ft_strlcat(dst, "\n", l);
	return (true);
}

int	*init_int_array(int num)
{
	int	*l_i;

	l_i = ft_calloc(sizeof(int), num);
	l_i[LEN] = 0;
	l_i[ITER] = 0;
	return (l_i);
}
