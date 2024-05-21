/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:12:01 by ajbari            #+#    #+#             */
/*   Updated: 2024/01/21 08:30:36 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		ft_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

int	ft_putnbr(long n, unsigned int base, int type)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		count += ft_putnbr(-n, base, type);
	}
	else if (n >= base)
	{
		count += ft_putnbr(n / base, base, type);
		count += ft_putnbr(n % base, base, type);
	}
	else if (type == 1 && s[n] >= 97 && s[n] <= 122)
		count += ft_putchar(s[n] - 32);
	else
		count += ft_putchar(s[n]);
	return (count);
}

int	sub_printf(int specifier, va_list ap)
{
	if (specifier == 0)
		return (0);
	if (specifier == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int), 10, 0));
	if (specifier == 'x')
		return (ft_putnbr(((va_arg(ap, unsigned int))), 16, 0));
	if (specifier == 'X')
		return (ft_putnbr((va_arg(ap, unsigned int)), 16, 1));
	if (specifier == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int), 10, 0));
	if (specifier == 'p')
		return (ft_putaddress(va_arg(ap, unsigned long), 1));
	return (write(1, &specifier, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (*(++s) == '\0')
				return (count);
			count += sub_printf(*s, ap);
		}
		else
		{
			count += write(1, s, 1);
		}
		s++;
	}
	va_end(ap);
	return (count);
}
