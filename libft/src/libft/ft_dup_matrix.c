/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:58:27 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/20 17:58:28 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_matrix(char **m)
{
	char	**out;
	int		n_rows;
	int		i;

	i = 0;
	n_rows = ft_matrixlen(m);
	out = malloc(sizeof(char *) * (n_rows + 1));
	if (!out)
		return (NULL);
	while (m[i])
	{
		out[i] = ft_strdup(m[i]);
		if (!out[i])
		{
			ft_free_matrix(&out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}
