/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:43:44 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/21 08:35:50 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long p, int flag)
{
	int		count;
	char	*hexa;

	hexa = "0123456789abcdef";
	count = 0;
	if (flag == 1)
	{
		count += write(1, "0x", 2);
		flag = 0;
	}
	if (p >= 16)
	{
		count += ft_putaddress(p / 16, flag);
		count += ft_putaddress(p % 16, flag);
	}
	else
		count += ft_putchar(p[hexa]);
	return (count);
}
