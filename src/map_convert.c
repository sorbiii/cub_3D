/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:40 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 16:17:18 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	fill_map_lines(t_data *data, char **big_line)
{
	int		i;
	char	*one_line;

	i = 1;
	one_line = extract_one_line(data, big_line);
	while (one_line)
	{
		if (is_blank_line(one_line))
		{
			free(one_line);
			break ;
		}
		data->map[i] = one_line;
		i++;
		one_line = extract_one_line(data, big_line);
	}
	if (big_line && *big_line)
	{
		free(*big_line);
		*big_line = NULL;
	}
}

char	**convert_map(t_data *data, char **big_line, char *first_map_line)
{
	char	**new_map;
	char	*line_cpy;

	data->map = ft_calloc(2, sizeof(char *));
	if (!data->map)
	{
		free(first_map_line);
		error_and_exit(MALLOC_ERROR, data);
	}
	data->map[0] = first_map_line;
	line_cpy = ft_strdup(*big_line);
	if (!line_cpy)
		error_and_exit(MALLOC_ERROR, data);
	data->m_height = calculate_map_height(&line_cpy, data) + 1;
	free(line_cpy);
	new_map = ft_calloc(data->m_height + 1, sizeof(char *));
	if (!new_map)
		error_and_exit(MALLOC_ERROR, data);
	new_map[0] = data->map[0];
	free(data->map);
	data->map = new_map;
	fill_map_lines(data, big_line);
	return (data->map);
}

void	pad_map_lines(t_data *data, int max_w)
{
	int		i;
	char	*padded;

	i = 0;
	while (data->map[i])
	{
		padded = ft_calloc(max_w + 1, sizeof(char));
		ft_strlcpy(padded, data->map[i], max_w + 1);
		while ((int)ft_strlen(padded) < max_w)
			ft_strlcat(padded, " ", max_w + 1);
		free(data->map[i]);
		data->map[i] = padded;
		i++;
	}
}

void	add_spaces_to_map(t_data *data)
{
	int	i;
	int	j;
	int	max_w;

	max_w = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t')
			j++;
		while (data->map[i][j] && data->map[i][j] != ' ' &&
				data->map[i][j] != '\t')
			j++;
		if (j > max_w)
			max_w = j;
		i++;
	}
	pad_map_lines(data, max_w);
	data->m_width = max_w;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
