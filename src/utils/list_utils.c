/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:36:20 by sbars             #+#    #+#             */
/*   Updated: 2022/10/27 17:02:07 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*return_last_token(t_meta	*pkg)
{
	t_token	*last;

	if (!pkg->chain_head)
		return (NULL);
	else
		last = pkg->chain_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
