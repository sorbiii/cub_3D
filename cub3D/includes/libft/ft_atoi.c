/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:31:13 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 02:51:49 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}*/
int	ft_atoi(const char *nptr)
{
	int	i;	
	int	num;
	int	flag;
	int	m;

	flag = 0;
	num = 0;
	i = 0;
	m = 1;
	while ((nptr[i] < 14 && nptr[i] > 8) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
		flag++;
	}
	while (ft_isdigit(nptr[i]) == 1 && nptr[i])
		num = num * 10 + nptr[i++] - 48;
	if (flag > 1)
		return (0);
	return (num * m);
}
/*#include <stdio.h>
int	main(void)
{
	char *nptr = "+42lyon";
	int	result = ft_atoi(nptr);
	printf("%d", result);
	return (0);
}*/
