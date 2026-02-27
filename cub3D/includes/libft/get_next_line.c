/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:47:22 by mzapora           #+#    #+#             */
/*   Updated: 2025/04/28 18:05:11 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *buf, char *tmp)
{
	char	*tmp2;

	tmp2 = buf;
	buf = ft_gnl_strjoin(buf, tmp);
	free(tmp2);
	tmp2 = NULL;
	return (buf);
}

char	*ft_polishbuf(char *buf)
{
	char	*editedbuf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	editedbuf = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	while (buf[i])
	{
		editedbuf[j] = buf[i + 1];
		++i;
		++j;
	}
	free(buf);
	buf = NULL;
	return (editedbuf);
}

char	*polishline(char *buf)
{
	int		i;
	char	*output;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		++i;
	output = ft_calloc(i + 2, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		output[i] = buf[i];
		++i;
	}
	if (buf[i] && buf[i] == '\n')
		output[i] = '\n';
	return (output);
}

char	*line_read(int fd, char *buf)
{
	int		bytes_read;
	char	*tmp;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(tmp);
			free(buf);
			return (NULL);
		}
		tmp[bytes_read] = 0;
		buf = ft_joinfree(buf, tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(tmp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf[OPENFD];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_calloc(1, 1);
	buf[fd] = line_read(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = polishline(buf[fd]);
	buf[fd] = ft_polishbuf(buf[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char *line;
	int i = 0; 
	int fd = open("file", O_WRONLY);
	while (i < 4)
	{	
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	free(line);
	return (0);
}*/
