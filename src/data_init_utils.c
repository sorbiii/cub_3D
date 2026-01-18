#include "../includes/cube.h"

char *trim_spaces(const char *s)
{
	char *trim;

	if (!s)
		return (NULL);
	trim = ft_strtrim(s, " \t\r\n\v\f");
	return (trim);
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

void check_texture_extention(t_data *data, char *s)
{
	int fd;
	if (is_valid_map_extention(s, ".xpm", ft_strlen(".xpm")) == -1)
		error_and_exit(WRONG_EXTENTION, data);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		error_and_exit(FILE_OPEN_FAILURE, data);
}

int same_textures(t_data *data)
{
	if (check_no_duplicates(data->north_texture, data->east_texture, data->south_texture, data->west_texture) != 0)
		return (-1);
	return (0);
}

int is_valid_map_extention(char *s, char *extention, int extention_len)
{
	char *pos;
	int len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (len < extention_len)
		return (-1);
	pos = ft_strnstr(s, extention, len);
	if (!pos)
		return (-1);
	if (*(pos + extention_len) != '\0')
		return (-1);
	return (0);
}

void count_map_size(t_data *data, char **map, int start_idx)
{
	char *line;
	char *trim;
	int i;
	int num_of_elems;

	if (!data || !map)
		return ;
	data->m_width = 0;
	data->m_height = 0;
	i = start_idx; //start after textures, colors
	while (map[i])
	{
		trim = trim_spaces(map[i]);
		if (!trim || trim[0] == '\0')
		{
			free(trim);
			i++;
		}
		free(trim);
		break;
	}
	while (map[i])
	{
		line = map[i];
		trim = trim_spaces(line);
		if (!trim || trim[0] == '\0')
		{
			free(trim);
			break;
		}
		free(trim);
		if ((int)ft_strlen(line) > data->m_width)
			data->m_width = ft_strlen(line);
		data->m_height++;
		i++;
	}
}

int	check_no_duplicates(char *s1, char *s2, char *s3, char *s4)
{
	char	*strs[4];
	int		i;
	int		j;

	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	strs[3] = s4;
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strcmp(strs[i], strs[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && (*s1 == *s2))
	{
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
