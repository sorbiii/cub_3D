#include "../includes/cube.h"

char	**copy_map(t_data *map)
{
	char	**mapcpy;
	int		i;

	i = 0;
	mapcpy = calloc(map->m_height + 1, sizeof(char *));
	if (!mapcpy)
		return (NULL);
	while (i < map->m_height)
	{
		mapcpy[i] = ft_strdup(map->map[i]);
		if (!mapcpy[i])
		{
			while (--i >= 0)
				free(mapcpy[i]);
			free(mapcpy);
			return (NULL);
		}
		i++;
	}
	mapcpy[i] = NULL;
	return (mapcpy);
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
