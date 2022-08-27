/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytao <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:04:02 by ytao              #+#    #+#             */
/*   Updated: 2021/11/06 18:04:03 by ytao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*lstcpy;

	i = 0;
	lstcpy = lst;
	while (lstcpy != NULL)
	{
		lstcpy = lstcpy->next;
		i++;
	}
	return (i);
}
