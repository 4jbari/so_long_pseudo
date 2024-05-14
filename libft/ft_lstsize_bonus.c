/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:58:02 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:01:32 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lstcount;
	size_t	count;

	count = 0;
	lstcount = lst;
	while (lstcount)
	{
		lstcount = lstcount->next;
		count++;
	}
	return (count);
}
