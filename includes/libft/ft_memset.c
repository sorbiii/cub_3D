/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:06:39 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 03:00:20 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_memset(void *s, char c, int n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = s;
	while (i < n)
	{
		*str = c;
		str++;
		i++;
	}
	return (s);
}
