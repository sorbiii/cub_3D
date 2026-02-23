#include "../includes/cube.h"

void null_struct(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->f_color = -1; 
	data->c_color = -1;
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
	close(fd);
}
