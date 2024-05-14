/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:22:40 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:04:55 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	uc;

	uc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *) &s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *) &s[i]);
	return (0);
}
