/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:33 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 16:25:04 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	dispatch_element(t_data *data, char **line, int *num_of_elems)
{
	if (ft_strncmp(*line, "NO", 2) == 0 && ((*line)[2] == ' '
		|| (*line)[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->north_texture);
	else if (ft_strncmp(*line, "SO", 2) == 0 && ((*line)[2] == ' '
		|| (*line)[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->south_texture);
	else if (ft_strncmp(*line, "WE", 2) == 0 && ((*line)[2] == ' '
		|| (*line)[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->west_texture);
	else if (ft_strncmp(*line, "EA", 2) == 0 && ((*line)[2] == ' '
		|| (*line)[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->east_texture);
	else if ((*line)[0] == 'F' && ((*line)[1] == ' '
		|| (*line)[1] == '\t'))
		colors_to_struct(data, line, num_of_elems, &data->f_color);
	else if ((*line)[0] == 'C' && ((*line)[1] == ' '
		|| (*line)[1] == '\t'))
		colors_to_struct(data, line, num_of_elems, &data->c_color);
	else
	{
		free(*line);
		error_and_exit(INCORRECT_CHAR, data);
	}
}

void	extract(t_data *data, char **line, int *num_of_elems)
{
	if (!line || !*line)
		return ;
	dispatch_element(data, line, num_of_elems);
}

char	*get_next_non_blank_line(t_data *data, char **line)
{
	char	*ln;

	ln = extract_one_line(data, line);
	while (ln && is_blank_line(ln))
	{
		free(ln);
		ln = extract_one_line(data, line);
	}
	return (ln);
}

char	*textures_colors_to_struct(t_data *data, char **line)
{
	int		num_of_elem;
	char	*ln;
	char	*trimmed;

	num_of_elem = 0;
	null_struct(data);
	while (num_of_elem < 6)
	{
		ln = get_next_non_blank_line(data, line);
		if (!ln)
			error_and_exit(WRONG_TEXTURE_OR_COLOR, data);
		trimmed = trim_spaces(ln);
		free(ln);
		extract(data, &trimmed, &num_of_elem);
		free(trimmed);
	}
	return (get_next_non_blank_line(data, line));
}
