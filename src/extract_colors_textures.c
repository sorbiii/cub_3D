#include "../includes/cube.h"

int parse_rgb(char *s)
{
	return 0;
}

void extract_colors_to_struct(char *line, int *num_of_elems, int *color) //zmienic map error na odpowiednie dla erroru
{
	char *val;

	if (*color != -1)
	{
		free(line);
		error_and_exit(MAP_ERROR);
	}
	val = trim_spaces(line + 1);
	if (val)
		*color = parse_rgb(val);
	else
		*color = parse_rgb("");
	if (val)
		free(val);
	if (*color == -1)
	{
		free(line);
		error_and_exit(MAP_ERROR);
	}
	(*num_of_elems)++;
}

void extract_textures_to_struct(char *line, int *num_of_elems, char **texture)
{
	int fd;
	char *val;

	if (!num_of_elems || !texture)
	{
		free(line);
		error_and_exit(MAP_ERROR);
	}
	if (*texture)
	{
		free(line);
		error_and_exit(MAP_ERROR);
	}
	val = trim_spaces(line + 2);
	if (val)
		*texture = ft_strdup(val);
	else
		*texture = ft_strdup("");
	if (val)
		free(val);
	(*num_of_elems)++;
	check_texture_extention(*texture);
}

void extract_utils(t_data *data, char *line, int *num_of_elems)
{
	char *val;

	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			extract_textures_to_struct(line, num_of_elems, &data->north_texture);
	else if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		extract_textures_to_struct(line, num_of_elems, &data->south_texture);
	else if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		extract_textures_to_struct(line, num_of_elems, &data->west_texture);
	else if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		extract_textures_to_struct(line, num_of_elems, &data->east_texture);
	else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
		extract_colors_to_struct(line, num_of_elems, &data->f_color);
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		extract_colors_to_struct(line, num_of_elems, &data->c_color);
}

int extract_textures_colors(t_data *data, char **map)
{
	int i;
	char *line;
	int num_of_elems;

	if (!data || !map)
		return (0);
	null_struct(data);
	num_of_elems = 0;
	i = 0;
	while (map[i] && num_of_elems < 6)
	{
		line = trim_spaces(map[i]);
		if (!line || line[0] == '\0')
		{
			if (line)
				free(line);
			i++;
		}
		extract_utils(data, line, &num_of_elems);
		free(line);
		i++;
	}
	if (num_of_elems < 6)
		error_and_exit(MAP_NOT_END);
	return (i);
}
