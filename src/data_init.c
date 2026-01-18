#include "../includes/cube.h" 

// void	print_char_array(char **arr)
// {
// 	int i;

// 	if (!arr)
// 		return;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("dupa%s dupa\n", arr[i]);
// 		i++;
// 	}
// }

char **map_convert(t_data *data, char **map)
{
	int i;
	int start_idx;
	char **new_map;

	start_idx = extract_textures_colors(data, map);
	if (start_idx == -1)
	{
		free_double_arr(map);
		error_and_exit(MAP_NOT_END, data);
	}
	if (same_textures(data) == -1)
	{
		free_double_arr(map);
		error_and_exit(WRONG_TEXTURE, data);
	}
	count_map_size(data, map, start_idx);
	new_map = malloc(sizeof(char *) * (data->m_height + 1));
	if (!new_map)
		return (free_double_arr(map), NULL);
	i = 0;
	while (i < data->m_height && map[start_idx + i])
	{
		new_map[i] = malloc(data->m_width + 1);
		if (!new_map[i])
			return (free_map_rows(new_map, i), free_double_arr(map), NULL);
		ft_memset(new_map[i], ' ', data->m_width);
		ft_memcpy(new_map[i], map[start_idx + i], ft_strlen(map[start_idx + i]));
		new_map[i][data->m_width] = '\0';
		i++;
	}
	new_map[i] = NULL;
	free_double_arr(map);
	return (new_map);
}

char **create_map(t_data *data, int fd)
{
	char *buffer;
	char *line;
	char *temp;
	char **map;

	buffer = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = buffer;
		buffer = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	free(line);
	return (map_convert(data, map));
}

void read_file(t_data *data, char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit(FILE_OPEN_FAILURE, data);
	data->map = create_map(data, fd);
}

void init_data(int argc, char **argv, t_data *data)
{
	if(argc != 2)
		error_and_exit(WRONG_ARG_NUM, data);
	if (is_valid_map_extention(argv[1], ".cub", ft_strlen(".cub")) == -1)
		error_and_exit(WRONG_EXTENTION, data);
	read_file(data, argv[1]);
}
