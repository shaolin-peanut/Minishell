/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:47:12 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 11:48:03 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// if (pkg->prompt)
	//    free(pkg->prompt);
	/*if (pkg->str)
	{
		pkg->str = NULL;
		free(pkg->str);
	}*/

void	free_all(t_meta *pkg)
{
	if (pkg->paths != NULL)
		free(pkg->paths);
	if (pkg)
		free(pkg);
}
