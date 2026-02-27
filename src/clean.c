/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:57:12 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/27 16:46:27 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_ptr(void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	free_everything(t_data *data)
{
	if (!data)
		return ;
	destroy_mlx(data);
	free_ptr((void **)&data->north_texture);
	free_ptr((void **)&data->south_texture);
	free_ptr((void **)&data->west_texture);
	free_ptr((void **)&data->east_texture);
	if (data->map)
	{
		free_double_arr(data->map);
		data->map = NULL;
	}
	free_ptr((void **)&data->line_map);
	free_ptr((void **)&data->plr_info);
	free_ptr((void **)&data->ray_info);
	free_ptr((void **)&data->keys);
	free_ptr((void **)&data->mlx_info);
	free(data);
}

char	*str_whitespace_cleaner(t_data *data, char *s, int i)
{
	char	*str;
	int		count;

	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			count++;
		i++;
	}
	str = malloc((count * sizeof(char)) + 1);
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

void	free_double_arr(char **arr)
{
	int	j;

	if (!arr)
		return ;
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
