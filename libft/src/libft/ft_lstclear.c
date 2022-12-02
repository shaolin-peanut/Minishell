/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:14:21 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 20:14:23 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*entry;

	if (lst)
	{
		entry = *lst;
		while (entry)
		{
			tmp = entry->next;
			if (del)
			{
				del(entry->content);
			}
			free(entry);
			entry = tmp;
		}
		*lst = NULL;
	}
}
