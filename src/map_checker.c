#include "../includes/cube.h"

int	map_checker(t_data *data)
{
	char **m_cpy;

	if (!data)
		return (-1);
	incorect_chars_checker(data, 0, 0, 0);
	m_cpy = copy_map(data);
	if (!m_cpy)
		error_and_exit(MALLOC_ERROR, data);
	is_map_closed(data, m_cpy, 0, 0);
	free_double_arr(m_cpy);
	return (0);
}

void	incorect_chars_checker(t_data *d, int y, int x, int count)
{
	while (y <= d->m_height && d->map[y])
	{
		x = 0;
		while (d->map[y][x])
		{
			if (is_valid_char(d->map[y][x]))
				error_and_exit(INCORRECT_CHAR, d);
			if (d->map[y][x] == 'S' || d->map[y][x] == 'E' || \
				d->map[y][x] == 'N' || d->map[y][x] == 'W')
			{
				d->plr_facing = d->map[y][x];
				d->plr_x = x + 0.5;
				d->plr_y = y + 0.5;
				d->map[y][x] = 'P';
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		error_and_exit(TOO_MANY_PLRS, d);
	return ;
}

void	is_map_closed(t_data *data, char **m, int x, int y)
{
	while (m[y] && y <= data->m_height)
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '0' || m[y][x] == 'P')
			{
				if (map_close_helper(m, y, x))
				{
					free_double_arr(m);
					error_and_exit(MAP_ERROR, data);
				}
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
