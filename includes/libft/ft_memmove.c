/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:20 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/16 17:18:16 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (d > s)
	{
		while (n--)
			((char *)d)[n] = ((char *)s)[n];
	}
	else if (s > d)
	{
		while (i < n)
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	return (dest);
}
