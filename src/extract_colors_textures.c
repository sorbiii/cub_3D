#include "../includes/cube.h"

int	rgb_connect_and_errors(char **nums)
{
	int r;
	int g;
	int b;
	int result;

	r = ft_atoi(nums[0]);
	g = ft_atoi(nums[1]);
	b = ft_atoi(nums[2]);
	result = (r << 16) | (g << 8) | b;
	free_double_arr(nums);
	return (result);
}

int parse_rgb(t_data *data, char *s, int result, char *trimed)
{
	char **nums;

	trimed = str_whitespace_cleaner(data, s, 0);
	nums = ft_split(trimed, ',');
	free(trimed);
	if (!nums || !nums[0] || !nums[1] || !nums[2])
	{
		if (nums)
			free_double_arr(nums);
		error_and_exit(MALLOC_ERROR, data);
	}
	result = rgb_connect_and_errors(nums);
	return (result);
}

void colors_to_struct(t_data *data, char *line, int *num_of_elems, int *color)
{
	char *val;

	if (*color != -1)
		error_and_exit(MAP_ERROR, data);
	val = trim_spaces(line + 1);
	if (val)
		*color = parse_rgb(data, val, 0, NULL);
	else
		*color = parse_rgb(data, "", 0, NULL);
	if (val)
		free(val);
	if (*color == -1)
		error_and_exit(MAP_ERROR, data);
	(*num_of_elems)++;
}

void textures_to_struct(t_data *data, char *line, int *num_of_elems, char **texture)
{
	int fd;
	char *val;

	if (!num_of_elems || !texture)
		error_and_exit(MAP_ERROR, data);
	if (*texture)
		error_and_exit(MAP_ERROR, data);
	val = trim_spaces(line + 2);
	if (val)
		*texture = ft_strdup(val);
	else
		*texture = ft_strdup("");
	if (val)
		free(val);
	(*num_of_elems)++;
	check_texture_extention(data, *texture);
}

void extract_utils(t_data *data, char *line, int *num_of_elems)
{
	char *val;

	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			textures_to_struct(data, line, num_of_elems, &data->north_texture);
	else if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->south_texture);
	else if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->west_texture);
	else if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
		textures_to_struct(data, line, num_of_elems, &data->east_texture);
	else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
		colors_to_struct(data, line, num_of_elems, &data->f_color);
	else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
		colors_to_struct(data, line, num_of_elems, &data->c_color);
}

int extract_textures_and_colors(t_data *data, char **map)
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
			continue;
		}
		extract_utils(data, line, &num_of_elems);
		free(line);
		i++;
	}
	if (num_of_elems < 6)
		return (-1);
	return (i);
}
