/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:32:40 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/15 22:30:36 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len1)
		return (ft_strdup(""));
	if (start + len > len1)
		len = len1 - start;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}

/*int	main(void)
{
	char const *s = "0123456789";
	unsigned int start = 1;
	size_t len = 3;
	char *result;
	result = ft_substr(s, start, len);
	printf("%s", result);
	return (0);
}*/