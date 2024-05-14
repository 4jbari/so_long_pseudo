/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:14:02 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/04 11:10:33 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse_str(char *s)
{
	int		i;
	char	tmp;
	int		len;

	len = ft_strlen(s) - 1;
	i = 0;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		len--;
		i++;
	}
	return (s);
}

static size_t	count_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*sub_itoa(int nbr, char *s)
{
	int	sign_flag;
	int	i;

	i = 0;
	sign_flag = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		sign_flag = 1;
	}
	while (nbr > 0)
	{
		s[i] = (nbr % 10) + 48;
		nbr /= 10;
		i++;
	}
	if (sign_flag == 1)
	{
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	s = malloc(count_nbr(n) * sizeof(char) + 1);
	if (!s)
		return (0);
	if (n == 0)
	{
		s[i++] = '0';
		s[i] = '\0';
		return (s);
	}
	s = sub_itoa (n, s);
	reverse_str (s);
	return (s);
}
