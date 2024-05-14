/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:10:58 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:02:58 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst1;
	unsigned const char	*src1;

	dst1 = dst;
	src1 = src;
	if (dst1 == src1)
		return (dst);
	i = 0;
	if (src1 < dst1)
	{
		while (len-- > 0)
			dst1[len] = src1[len];
	}
	else
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
