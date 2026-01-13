#include "../includes/cube.h"

char **map_convert(t_data *data, char **map)
{
	int i;
	int start_idx;
	char **new_map;

	i = 0;
	start_idx = extract_textures_colors(data, map);
	count_map_size(data, map, start_idx);
	new_map = (char **)malloc(sizeof(char *) * data->m_witdh);
	while (i < data->m_witdh)
	{
		new_map[i] = (char *)malloc(sizeof(char *) * data->m_heigh);
		//one line - wszystko do data->map wpisac po linijce 
		i++;
	}
	//free map
	//map trzeba teraz dac do data->map i bedzie klasa
	return (NULL);
	//return new_map
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
	if (is_valid_map_extention(argv[1], ".cub", ft_strlen(".cub")) == -1)
		 (error_and_exit(WRONG_EXTENTION));
	read_file(data, argv[1]);
	//zparsowanie mapy - wyciagnac player, map width, height 
}