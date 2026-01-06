/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 08:22:33 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 03:21:21 by mzapora          ###   ########.fr       */
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
int	ft_fromback(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i--;
	}
	return (i);
}

int	ft_fromstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*dest;
	int		l;

	i = 0;
	j = ft_fromback(s1, set);
	k = ft_fromstart(s1, set);
	if (k > j)
		return (ft_strdup(""));
	l = j - k + 1;
	dest = malloc(l + 1);
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = s1[k + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	char const *s1 = " 123456789 	";
	char const *set = "	 ";
	char *wytrymowany = ft_strtrim(s1, set);
	printf("%s", wytrymowany);
	return (0); 
}*/
