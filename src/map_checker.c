#include "../includes/cube.h"

int	map_checker(t_data *data)
{
	if (!data)
		return (-1);
	incorect_chars_checker(data);
	is_map_closed(data);
}

void	incorect_chars_checker(t_data *d)
{
	int y;
	int x;

	while (d->map[y] && y <= d->m_heigh)
	{
		x = 0;
		while (d->map[y][x])
		{
			if (d->map[y][x] != "S" && d->map[y][x] != "N" && \
			d->map[y][x] != "W" && d->map[y][x] != "E" && \
			d->map[y][x] != "0" && d->map[y][x] != "1")
				error_and_exit(INCORECT_CHAR);
			else
				x++;
		}
		y++;
	}
	return ;
}

void	is_map_closed(t_data *d)
{
	int x;
	int	y;

	y = 0;
	x = 0;
	char **m_cpy;

	m_cpy = copy_map(d->map);
	if (!m_cpy)
		error_and_exit(MALLOC_ERROR);
	while (m_cpy[y][x])
	{
		if (m_cpy[y][x] == '1')
			wall_fill(m_cpy, x, y);
	}
	return ;
}
