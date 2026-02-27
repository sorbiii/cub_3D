/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:06:29 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/16 17:08:30 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*sr;
	unsigned char			*ds;

	if (!dest && !src)
		return (0);
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;
	while (n > 0)
	{
		ds[n - 1] = sr[n - 1];
		n--;
	}
	return (ds);
}
