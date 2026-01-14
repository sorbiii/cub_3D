/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:57:12 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/14 16:13:47 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	clean_map_copy(char **map)
{
    int	i;
    
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

char	*str_whitespace_cleaner(char *s, int i)
{
	char *str;
	int count;

	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			count++;
		i++;
	}
	str = malloc((count * sizeof(char)) + 1 );
	if (!str)
		error_and_exit(MALLOC_ERROR);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			str[count++] = s[i];
		i++;
	}
	str[count] = '\0';
	return (str);
}
