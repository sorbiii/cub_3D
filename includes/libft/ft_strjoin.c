/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 07:10:50 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 03:09:49 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return ((size_t)i);
}*/
char	*ft_strjoin(char const *s1, char const *s2)
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
/*int	main(void)
{
	const char *s1 = "123456";
	const char *s2 = "7890";
	char *result;
	result = ft_strjoin(s1, s2);
	printf ("%s", result);
	return (0);
}*/
