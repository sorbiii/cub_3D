#include "../includes/cube.h"

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

t_data *map_create(t_data *data, char **map)
{
	//trzeba sprawdzic tu kolorki teksturki potem dopiero mapę!
	//sprawdzic jak poprzednia funkcja działa na pustych liniach
	return (NULL);
}

t_data *create_map(t_data *data, int fd)
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
		buffer == ft_strjoin(buffer, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	free(line);
	return (map_create(data, map));
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
		return (error_and_exit(WRONG_ARG_NUM));
	if (is_valid_extention(argv[1]) == -1)
		return (error_and_exit(WRONG_EXTENTION));
	read_file(data, argv[1]);
	//pierwszy gnl - do kolorow i teksturek - WHITESPACES!
	//sprawdzenie kolorow
	//sprawdzenie teksturek
	//zparsowanie mapy - wyciagnac player, map width, height 
}