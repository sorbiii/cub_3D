/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:33:51 by mzapora           #+#    #+#             */
/*   Updated: 2025/05/10 02:45:29 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_arg(char const *s, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (i);
}

static void	*ft_clean(char **list, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static int	count_word(char *s, int c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**list;

	j = 0;
	i = count_arg((char *)s, c);
	list = malloc((i + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			list[j] = malloc(count_word((char *)s, c) + 1);
			if (list[j] == NULL)
				return (ft_clean(list, i));
			ft_strlcpy(list[j++], s, count_word((char *)s, c) + 1);
			s += count_word((char *)s, c) - 1;
		}
		s++;
	}
	list[j] = NULL;
	return (list);
}
