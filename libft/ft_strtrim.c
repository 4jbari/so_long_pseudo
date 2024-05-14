/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:23:31 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:08:02 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1 == set[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	skip;
	size_t	ls;

	skip = 0;
	if (!s1 || !set)
		return (0);
	ls = ft_strlen(s1);
	while (s1[skip] && set_check(s1[skip], set) == 1)
		skip++;
	while (ls > skip && set_check(s1[ls - 1], set) == 1)
		ls--;
	return (ft_substr(s1, skip, ls - skip));
}
