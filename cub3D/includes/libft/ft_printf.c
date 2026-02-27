/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:19:16 by mzapora           #+#    #+#             */
/*   Updated: 2025/01/28 15:00:40 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptrp(unsigned long long i)
{
	int		j;
	char	*x;

	x = "0123456789abcdef";
	j = 0;
	if (i >= 16)
	{
		j += ft_putptrp(i / 16);
		i = i % 16;
	}
	j += write(1, &x[i], 1);
	return (j);
}

int	ft_putptr(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	else
	{
		i += write(1, "0x", 2);
		i += ft_putptrp(n);
	}
	return (i);
}

int	cformat(char *format, va_list va)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_p(va_arg(va, int));
	else if (*format == 's')
		i += ft_putstr_p(va_arg(va, char *));
	else if (*format == 'p')
		i += ft_putptr(va_arg(va, long long));
	else if (*format == 'd')
		i += ft_putdigit_p(va_arg(va, int), 0);
	else if (*format == 'i')
		i += ft_putdigit_p(va_arg(va, int), 0);
	else if (*format == 'u')
		i += ft_putuint_p(va_arg(va, int));
	else if (*format == 'x')
		i += ft_puthex_p(va_arg(va, int), 'x');
	else if (*format == 'X')
		i += ft_puthex_p((va_arg(va, int)), 'X');
	else
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	i;

	if (!format)
		return (0);
	va_start(va, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			i += cformat((char *)++format, va);
		}
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(va);
	return (i);
}
