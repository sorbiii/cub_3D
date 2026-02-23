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
				error_and_exit(INCORRECT_CHAR, data);
			}
		}
		height += 1;
		free(ln);
		ln = extract_one_line(data, line);
	}
	free(ln);
	return (height);
}
