#include "../includes/cube.h"

char *trim_spaces(const char *s)
{
	char *trim;

	if (!s)
		return (NULL);
	trim = ft_strtrim(s, " \t\r\n\v\f");
	return (trim);
}

int parse_rgb(char *s)
{
	return 0;
}

void null_struct(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->f_color = -1;
	data->c_color = -1;
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
	if (color == -1)
	{
		free(line);
		error_and_exit(MAP_ERROR);
	}
	num_of_elems++;
}
void extract_textures_to_struct(char *line, int *num_of_elems, char **texture)
{
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
}

void extract_utils(t_data *data, char **line, int *num_of_elems)
{
	char *val;

	if (ft_strncmp(line, "NO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			extract_textures_to_struct(line, &num_of_elems, &data->north_texture);
		else if (ft_strncmp(line, "SO", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			extract_textures_to_struct(line, &num_of_elems, &data->south_texture);
		else if (ft_strncmp(line, "WE", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			extract_textures_to_struct(line, &num_of_elems, &data->west_texture);
		else if (ft_strncmp(line, "EA", 2) == 0 && (line[2] == ' ' || line[2] == '\t'))
			extract_textures_to_struct(line, &num_of_elems, &data->east_texture);
		else if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
			extract_colors_to_struct(line, &num_of_elems, &data->f_color);
		else if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
			extract_colors_to_struct(line, &num_of_elems, &data->c_color);
}

void extract_textures_colors(t_data *data, char **map)
{
	int i;
	char *line;
	int num_of_elems;

	if (!data || !map)
		return ;
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
		extract_utils(data, &line, &num_of_elems);
		free(line);
		i++;
	}
	if (num_of_elems < 6)
		error_and_exit(MAP_ERROR);
}

void count_map_size(t_data *data, char **map)
{
	data->m_witdh = 0;
	data->m_heigh = 0;
	printf("north texture: %s\n", data->north_texture);
	printf("south texture: %s\n", data->south_texture);

}

int is_valid_extention(char *s)
{
	char *pos;
	int len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (len < 4)
		return (-1);
	pos = ft_strnstr(s, ".cub", len);
	if (!pos)
		return (-1);
	if (*(pos + 4) != '\0')
		return (-1);
	return (0);
}
char **map_convert(t_data *data, char **map)
{
	extract_textures_colors(data, map);
	count_map_size(data, map);
	//trzeba sprawdzic tu kolorki teksturki potem dopiero mapę!
	//sprawdzic jak poprzednia funkcja działa na pustych liniach
	return (NULL);
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
		error_and_exit(FILE_OPEN_FAILURE);
	data->map = create_map(data, fd);
}

void init_data(int argc, char **argv, t_data *data)
{
	if(argc != 2)
		 (error_and_exit(WRONG_ARG_NUM));
	if (is_valid_extention(argv[1]) == -1)
		 (error_and_exit(WRONG_EXTENTION));
	read_file(data, argv[1]);
	//zparsowanie mapy - wyciagnac player, map width, height 
}