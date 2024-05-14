/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:08:10 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:05:36 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*a;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	a = malloc (ls1 + ls2 + 1);
	if (a == 0)
		return (0);
	ft_strlcpy(a, s1, ls1 + ls2 + 1);
	ft_strlcat(a, s2, ls1 + ls2 + 1);
	return (a);
}
