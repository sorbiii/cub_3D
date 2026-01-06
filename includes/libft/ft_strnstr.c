/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:51:22 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/16 17:16:37 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = ft_strlen(little);
	if (!big && len == 0)
		return (0);
	if (i == 0)
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j + i <= len && big[j + i - 1] != '\0')
	{
		if (big[j] == little[0])
		{
			k = 0;
			while (k < i && big[j + k] == little[k])
				k++;
			if (k == i)
				return ((char *)big + j);
		}
		j++;
	}
	return (NULL);
}
/*int	main(void)
{
	const char *big = "aabcabcd";
	const char *little = "abcd";
	size_t		len = 9;
	char 		*result = ft_strnstr(big, little, len);
	printf("%s", result);
	return (0);
}*/
