#include "../includes/cube.h"

void	error_and_exit(int i)
{
	if (i == INCORECT_CHAR)
	{
		write(2, "INCORRECT CHAR\n", 15);
		exit(-1);
	}
	if (i == MALLOC_ERROR)
	{
		write(2, "MALLOC ERROR\n", 14);
		exit(-1);
	}
	if (i == TOO_MANY_PLRS)
	{
		write(2, "WRONG AMOUNT OF PLAYERS\n", 25);
		exit(-1);
	}
	if (i == MAP_ERROR)
	{
		write(2, "MAP UNCLOSED\n", 13);
		exit(-1);
	}
}

char	**copy_map(t_data *map)
{
	char	**mapcpy;
	int		i;

	i = 0;
	mapcpy = calloc(map->m_heigh + 1, sizeof(char *));
	if (!mapcpy)
		return (NULL);
	while (i < map->m_heigh)
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
