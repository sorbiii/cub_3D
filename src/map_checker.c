#include "../includes/cube.h"

int	map_checker(t_data *data)
{
	char **m_cpy;

	if (!data)
		return (-1);
	incorect_chars_checker(data, 0, 0, 0);
	m_cpy = copy_map(data->map);
	if (!m_cpy)
		error_and_exit(MALLOC_ERROR);
	is_map_closed(m_cpy, 0, 0, data->m_heigh);
	printf("dupa");
	return (0);
}

void	incorect_chars_checker(t_data *d, int y, int x, int count)
{
	while (d->map[y] && y <= d->m_heigh)
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'S' || d->map[y][x] == 'E' || 
			d->map[y][x] == 'N' || d->map[y][x] == 'W')
			{
				count++;
				d->map[y][x] = 'P';
			}
			if (d->map[y][x] != "S" && d->map[y][x] != "N" && \
			d->map[y][x] != "W" && d->map[y][x] != "E" && \
			d->map[y][x] != "0" && d->map[y][x] != "1")
				error_and_exit(INCORECT_CHAR);
			else
				x++;
		}
		y++;
	}
	if (count != 1)
		error_and_exit(TOO_MANY_PLRS);
	return ;
}

void	is_map_closed(char **m, int x, int y, int heigh)
{
	while (m[y][x] && y <= heigh)
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '0' || m[y][x] == 'P')
			{
				if (m[y + 1][x] && m[y + 1][x] != '0' && m[y + 1][x] != '1')
					error_and_exit(MAP_ERROR);
				if (m[y - 1][x] && m[y - 1][x] != '0' && m[y - 1][x] != '1')
					error_and_exit(MAP_ERROR);
				if (m[y][x + 1] && m[y][x + 1] != '0' && m[y][x + 1] != '1')
					error_and_exit(MAP_ERROR);
				if (m[y][x - 1] && m[y][x - 1] != '0' && m[y][x - 1] != '1')
					error_and_exit(MAP_ERROR);
			}
			x++;
		}
		y++;
	}
	return ;
}
