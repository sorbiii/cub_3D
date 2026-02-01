/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:57:12 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/01 19:20:58 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void free_everything(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_double_arr(data->map);
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	free(data);
}

char	*str_whitespace_cleaner(t_data *data, char *s, int i)
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
		error_and_exit(MALLOC_ERROR, data);
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

void free_double_arr(char **arr)
{
	int j;
	
	j = 0;
	while (arr[j])
		free(arr[j++]);
	free(arr);
	return ;
}

void	free_map_rows(char **new_map, int count)
{
	while (--count >= 0)
		free(new_map[count]);
	free(new_map);
}

