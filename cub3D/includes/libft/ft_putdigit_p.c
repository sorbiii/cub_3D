/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:33:59 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/29 22:18:47 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putdigit_p(int nb, int i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar_p('-');
		nb = -nb;
		++i;
	}
	if (nb >= 10)
	{
		i = ft_putdigit_p(nb / 10, i);
		nb = nb % 10;
	}
	ft_putchar_p(nb + 48);
	i++;
	return (i);
}
