/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorbi <sorbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:57:12 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/04 22:30:22 by sorbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void free_everything(t_data *data)
{
	if (!data)
		return ;
	//data->map = NULL;
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	if (data->map)
		free_double_arr(data->map);
	if (data->line_map)
	{
    	free(data->line_map);
    	data->line_map = NULL;
	}
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
	if (arr)
		free(arr);
	return ;
}
