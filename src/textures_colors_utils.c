#include "../includes/cube.h"

int	parse_rgb(t_data *data, char *s, int result, char **line)
{
	char	**nums;
	char	*trimed;

	trimed = NULL;
	trimed = str_whitespace_cleaner(data, s, 0);
	nums = ft_split(trimed, ',');
	free(trimed);
	if (!nums || !nums[0] || !nums[1] || !nums[2]
		|| ft_strlen(nums[2]) > 3
		|| ft_strlen(nums[0]) > 3 || ft_strlen(nums[1]) > 3)
	{
		if (nums)
			free_double_arr(nums);
		free(s);
		if (line)
			free(*line);
		error_and_exit(WRONG_RGB, data);
	}
	result = rgb_connect_and_errors(nums, data, s, line);
	return (result);
}

void	colors_to_struct(t_data *data, char **line,
	int *num_of_elems, int *color)
{
	char	*val;

	if (!line || !*line)
		error_and_exit(MAP_ERROR, data);
	val = trim_spaces((*line) + 1);
	if (val)
		*color = parse_rgb(data, val, 0, line);
	else
		*color = parse_rgb(data, "", 0, line);
	if (val)
		free(val);
	if (*color == -1)
	{
		free(*line);
		*line = NULL;
		error_and_exit(MAP_ERROR, data);
	}
	(*num_of_elems)++;
}

void	textures_to_struct(t_data *data, char **line,
	int *num_of_elems, char **texture)
{
	char	*val;

	if (!num_of_elems || !texture || !line || !*line)
		error_and_exit(MAP_ERROR, data);
	val = trim_spaces((*line) + 2);
	if (val)
		*texture = ft_strdup(val);
	else
		*texture = ft_strdup("");
	if (val)
		free(val);
	if (!*texture)
	{
		free(*line);
		*line = NULL;
		error_and_exit(MALLOC_ERROR, data);
	}
	check_texture_extention(data, *texture, line);
	(*num_of_elems)++;
}
