#include "../includes/cube.h"

int is_blank_line(const char *s)
{
	int i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

// void print_char_array(char **arr)
// {
// 	int i;

// 	if (!arr)
// 		return;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("dupa%sdupa\n", arr[i]);
// 		i++;
// 	}
// }

char *remove_first_line(char **src_line, int rest_len)
{
	int len;
	int cut_len;
	char *new_line;

	if (!src_line || !*src_line)
		return (NULL);
	len = ft_strlen(*src_line);
	cut_len = len - rest_len;
	new_line = ft_calloc(rest_len + 1, 1);
	if (!new_line)
		return (NULL);
	if (rest_len > 0)
		ft_strlcpy(new_line, *src_line + cut_len, rest_len + 1);
	free(*src_line);
	*src_line = NULL;
	return (new_line);
}

char *extract_one_line(t_data *data, char **line)
{
	int i;
	char *new_line;
	int remain_len;

	if (!line || !*line || (*line)[0] == '\0')
		return (NULL);
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	new_line = ft_calloc(i + 1, 1);
	if (!new_line)
		error_and_exit(MALLOC_ERROR, data);
	ft_strlcpy(new_line, *line, i + 1);
	if ((*line)[i] == '\n')
	{
		remain_len = ft_strlen(*line + i + 1);
		*line = remove_first_line(line, remain_len);
	}
	else
		(*line)[0] = '\0';
	return (new_line);
}

char *textures_colors_to_struct(t_data *data, char **line)
{
	int num_of_elem;
	char *ln;

	num_of_elem = 0;
	null_struct(data);
	while (num_of_elem < 6)
	{
		ln = extract_one_line(data, line);
		while (ln && is_blank_line(ln))
		{
			free(ln);
			ln = extract_one_line(data, line);
		}
		if (!ln)
			error_and_exit(MAP_ERROR, data);
		char *trimmed = trim_spaces(ln);
		free(ln);
		ln = trimmed;
		extract_utils(data, &ln, &num_of_elem);
		free(ln);
	}
	ln = extract_one_line(data, line);
	while (ln && is_blank_line(ln))
	{
		free(ln);
		ln = extract_one_line(data, line);
	}
	return (ln);
}

int calculate_map_height(char **line, t_data *data)
{
	int i;
	int height;
	char *ln;

	i = 0;
	height = 0;
	ln = extract_one_line(data, line);
	while (ln)
	{
		while (is_blank_line(ln))
		{
			free(ln);
			ln = extract_one_line(data, line);
			if (!ln)
				return (height);
			if (!is_blank_line(ln))
			{
				free(ln);
				if (line && *line)
				{
					free(*line);
					*line = NULL;
				}
				error_and_exit(MAP_ERROR, data);
			}
		}
		height += 1;
		free(ln);
		ln = extract_one_line(data, line);
	}
	free(ln);
	return (height);
}

void read_from_file(t_data *data, int fd)
{
	char *line;
	char *temp;
	char *first_map_line;

	data->line_map = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = data->line_map;
		data->line_map = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	first_map_line = textures_colors_to_struct(data, &data->line_map);
	if (!first_map_line)
		error_and_exit(MAP_ERROR, data);
	data->map = convert_map(data, &data->line_map, first_map_line);
	add_spaces_to_map(data);
}

void init_data(int argc, char **argv, t_data *data)
{
	int fd;

	if (argc != 2)
		error_and_exit(WRONG_ARG_NUM, data);
	if (is_valid_extention(argv[1], ".cub", ft_strlen(".cub")) == -1)
		error_and_exit(WRONG_EXTENTION, data);
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_exit(FILE_OPEN_FAILURE, data);
	read_from_file(data, fd);
	//print_char_array(data->map);
	close(fd);
}
