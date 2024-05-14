/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:22:49 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:05:09 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*a;

	l = ft_strlen(s1);
	a = malloc(l + 1);
	if (a == 0)
		return (0);
	ft_strlcpy(a, s1, l + 1);
	return ((char *)a);
}
