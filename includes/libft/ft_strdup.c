/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:23:36 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 03:08:41 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	int			i;

	i = 0;
	while (s[i])
		i++;
	dest = malloc(i + 1);
	if (dest == NULL)
		return (dest);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int main(void)
{
	const char *s = "jdkaskaskdakdabcd123";
	char 		*result;
	result = ft_strdup(s);
	printf("%s", result);
	return (0);
}*/ 