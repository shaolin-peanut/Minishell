/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:34:45 by gmontaur          #+#    #+#             */
/*   Updated: 2021/10/14 20:34:46 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*last_el;

	if (!lst)
		return (NULL);
	res = NULL;
	last_el = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			break ;
		if (last_el)
			last_el->next = tmp;
		if (!res)
			res = tmp;
		last_el = tmp;
		lst = lst->next;
	}
	if (!tmp)
		ft_lstclear(&res, del);
	return (res);
}
