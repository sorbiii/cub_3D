#include "../includes/cube.h"

int	is_blank_line(const char *s)
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

void print_char_array(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		printf("dupa%s dupa\n", arr[i]);
		i++;
	}
}

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
	char *tmp;

	if (!line || (*line)[0] == '\0' || !*line)
		return (NULL);
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	new_line = ft_calloc(i + 1, 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, *line, i + 1);
	if (!is_blank_line(new_line))
    {
        tmp = trim_spaces(new_line);
        if (tmp)
        {
            free(new_line);
            new_line = tmp;
        }
    }
	if ((*line)[i] == '\n')
	{
		remain_len = ft_strlen(*line + i + 1);
		*line = remove_first_line(line, remain_len);
	}
	else
		(*line)[0] = '\0';
	return (new_line);
}

void textures_colors_to_struct(t_data *data, char **line)
{
	int num_of_elem;
    char *ln;

    num_of_elem = 0;
	null_struct(data);
    while (num_of_elem < 6)
    {
        ln = extract_one_line(data, line);
        while (is_blank_line(ln) == 1)
        {
            free(ln);
			ln = extract_one_line(data, line);
        }
        extract_utils(data, &ln, &num_of_elem);
        free(ln);
    }
	ln = extract_one_line(data, line);
	while (is_blank_line(ln) == 1 && ln)
	{
		free(ln);
		ln = extract_one_line(data, line);
	}
	free(ln);
}

void check_lines(t_data *data, char *line)
{
    int i;

    if (!line)
        return ;
    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
        {
        	if (line[i + 1] == '\n')
                error_and_exit(MAP_ERROR, data);
        }
        i++;
    }
}

// char **convert_map(t_data *data, char **big_line)
// {
// 	int i;
// 	char *one_line;
// 	char **new_map;

// 	i = 0;
// 	one_line = extract_one_line(data, big_line);
// 	while (one_line)
// 	{
// 		if (is_blank_line(one_line))
// 			break;
// 		new_map[i] = one_line;
// 		free(one_line);
// 		one_line = extract_one_line(data, big_line);
// 		i++;
// 	}
// 	new_map[i] = NULL;
// 	free(one_line);
// }

// do momentu mapy działamy na jednej linii
void read_from_file(t_data *data, int fd)
{
	char *buffer;
	char *line;
	char *temp;

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
	textures_colors_to_struct(data, &buffer);
	data->map = convert_map(data, &buffer);
	free(buffer);
}

void read_file(t_data *data, char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit(FILE_OPEN_FAILURE, data);
	read_from_file(data, fd);
	close(fd);
}

void init_data(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		error_and_exit(WRONG_ARG_NUM, data);
	if (is_valid_extention(argv[1], ".cub", ft_strlen(".cub")) == -1)
		error_and_exit(WRONG_EXTENTION, data);
	read_file(data, argv[1]);
}
