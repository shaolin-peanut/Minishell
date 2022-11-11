/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:03:09 by ytao              #+#    #+#             */
/*   Updated: 2022/10/26 13:36:09 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*start;
	t_list	*temp;

	if (!lst)
		return ;
	start = *lst;
	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
