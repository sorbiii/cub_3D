/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:54:41 by mzapora           #+#    #+#             */
/*   Updated: 2025/06/09 14:54:45 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*dest;
	unsigned char	*d;
	unsigned char	*p;

	p = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc(i + j + 1);
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (p[++i])
		dest[i] = p[i];
	j = -1;
	while (d[++j])
		dest[i + j] = d[j];
	dest[i + j] = '\0';
	return (dest);
}
