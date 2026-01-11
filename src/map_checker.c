#include "../includes/cube.h"

int	map_checker(t_data *data)
{
	char **m_cpy;

	if (!data)
		return (-1);
	incorect_chars_checker(data, 0, 0, 0);
	m_cpy = copy_map(data);
	if (!m_cpy)
		error_and_exit(MALLOC_ERROR);
	is_map_closed(m_cpy, 0, 0, data->m_heigh);
	return (0);
}

void	incorect_chars_checker(t_data *d, int y, int x, int count)
{
	while (y <= d->m_heigh && d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (is_valid_char(d->map[y][x]))
				error_and_exit(INCORECT_CHAR);
			if (d->map[y][x] == 'S' || d->map[y][x] == 'E' || \
				d->map[y][x] == 'N' || d->map[y][x] == 'W')
			{
				d->map[y][x] = 'P';
				count++;
			}
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
	while (m[y] && y <= heigh)
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '0' || m[y][x] == 'P')
			{
				if (map_close_helper(m, y, x))
					error_and_exit(MAP_ERROR);
				//if (map_close_helper(m, y, x))
				//	error_and_exit(MAP_ERROR);
				//if (map_close_helper(m, y, x))
				//	error_and_exit(MAP_ERROR);
				//if (map_close_helper(m, y, x))
				//	error_and_exit(MAP_ERROR);
			}
			x++;
		}
		y++;
	}
	return ;
}
int	map_close_helper(char **m, int y, int x)
{
	if (!m[y][x + 1] || is_valid(m[y][x + 1]))
		return (1);
	if (x == 0 || !m[y][x - 1] || is_valid(m[y][x - 1]))
		return (1);
	if (y == 0 || !m[y - 1][x] || is_valid(m[y - 1][x]))
		return (1);
	if (!m[y + 1][x] || is_valid(m[y + 1][x]))
		return (1);
	return (0);
}

int is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'P')
		return (1);
	else
		return (0);
}

int is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || (c < 14 && c > 7))
		return (0);
	else if (c == 'S' || c == 'W' || c == 'E' || c == 'N')
		return (0);
	return (1);
}
