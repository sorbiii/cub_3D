/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:55:22 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/15 23:43:04 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memaloc(int j)
{
	char	*str;

	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

static unsigned int	len(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i += 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*strcreate(int num, int j, char *result)
{
	while (num)
	{
		result[--j] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	unsigned int		j;
	unsigned int		num;
	char				*result;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	j = len(n);
	result = memaloc(j);
	if (!result)
		return (NULL);
	result[j] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		num = (unsigned int)(-n);
		result[0] = '-';
	}
	else
		num = (unsigned int)n;
	result = strcreate(num, j, result);
	return (result);
}
/*int	main(void)
{
	int	i;
	char *result;
	
	i = 2147483648;
	result = ft_itoa(i);
	printf("%s", result);
	return (0);
}*/
