/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:34:12 by lanlan            #+#    #+#             */
/*   Updated: 2022/08/27 17:44:36 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* count the row numbers of the matrix*/
int	ft_matrix_row_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

/* duplicate matrix m and return it */
char	**ft_matrixdup(char **matrix)
{
	char	**matrix_dup;
	int		row_len;
	int		i;

	i = 0;
	row_len = ft_matrix_row_len(matrix);
	matrix_dup = malloc(sizeof(char *) * (row_len + 1));
	if (!matrix_dup)
		return (NULL);
	while (matrix[i])
	{
		matrix_dup[i] = ft_strdup(matrix[i]);
		if (!matrix_dup[i])
		{
			free(matrix_dup);
			return (NULL);
		}
		i++;
	}
	matrix_dup[i] = NULL;
	return (matrix_dup);
}
