/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:41:51 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/16 17:15:21 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}*/
int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!dst && size == 0)
		return (0);
	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = 0;
	if (size <= i)
		return (k + size);
	while (size-- > i + 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (k + i);
}
/*int main()
{
    char dst[50] = "Hello ";
    char src[] = "world!";

    printf("Before ft_strlcat: %s\n", dst);
    int result = ft_strlcat(dst, src, 50);
    printf("After ft_strlcat: %s\n", dst);
    printf("Total length would be: %d\n", result);

    return 0;
}*/
