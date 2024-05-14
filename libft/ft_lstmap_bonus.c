/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 19:22:54 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:00:46 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*cnt;

	head = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		cnt = f(lst->content);
		new = ft_lstnew(cnt);
		if (!new)
		{
			del(cnt);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
