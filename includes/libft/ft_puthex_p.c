/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 00:23:17 by mzapora           #+#    #+#             */
/*   Updated: 2025/01/28 15:02:06 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putx(char *x, unsigned int i)
{
	int	j;

	j = 0;
	if (i >= 16)
	{
		j += putx(x, i / 16);
		i = i % 16;
	}
	j += write(1, &x[i], 1);
	return (j);
}

int	ft_puthex_p(unsigned int i, int c)
{
	char	*xx;
	char	*x;
	int		j;

	j = 0;
	xx = "0123456789ABCDEF";
	x = "0123456789abcdef";
	if (c == 'x')
		j = putx(x, i);
	else if (c == 'X')
		j = putx(xx, i);
	return (j);
}
/*int	main()
{
	int i = 4456;
	char c = 'x';
	int	j = ft_puthex_p(i, (int)c);
	printf("liczba wypisanych""%d",j);
	return (0);
}*/
