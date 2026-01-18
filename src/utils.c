#include "../includes/cube.h"

void	error_and_exit(int i)
{
	if (i == INCORRECT_CHAR)
		write(2, "INCORRECT CHAR\n", 15);
	else if (i == MALLOC_ERROR)
		write(2, "MALLOC ERROR\n", 14);
	else if (i == TOO_MANY_PLRS)
		write(2, "WRONG AMOUNT OF PLAYERS\n", 25);
	else if (i == MAP_ERROR)
		write(2, "MAP UNCLOSED\n", 13);
	else if (i == FILE_OPEN_FAILURE)
		write(2, "ERROR WHILE OPENING FILE\n", 25);
	else if (i == WRONG_ARG_NUM)
		write(2, "WRONG NUMBER OF ARGUMENTS\n", 26);
	else if (i == WRONG_EXTENTION)
		write(2, "WRONG EXTENTION\n", 16);
	exit(-1);
}

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
