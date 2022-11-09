/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:50 by sbars             #+#    #+#             */
/*   Updated: 2022/11/09 15:31:30 by sbars            ###   ########.fr       */
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
