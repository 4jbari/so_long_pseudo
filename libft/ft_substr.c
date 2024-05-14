/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:18 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:08:18 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	lss;
	size_t	ls;

	lss = 0;
	if (!s)
		return (0);
	ls = ft_strlen(s);
	if (start > ls)
	{
		lss = 0;
		start = ls;
	}
	else if (ls - start < len)
		lss = ls - start;
	else if (ls - start >= len)
		lss = len;
	ss = malloc(lss * sizeof(char) + 1);
	if (ss == 0)
		return (0);
	ft_strlcpy(ss, &s[start], lss + 1);
	return (ss);
}
