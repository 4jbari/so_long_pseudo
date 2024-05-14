/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:12 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:01:59 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*s1;

	uc = (unsigned char)c;
	s1 = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == uc)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}
