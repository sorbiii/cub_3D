#include <stdlib.h>
#include "includes/cube.h"

int main(void)
{
	char *map[] = {
        " 1111111",
        " 1010001",
        " 10S0001",
        " 1111111",
        NULL
    };
    t_data *test;
    test = malloc(sizeof(t_data));
    test->map = map;
    test->m_heigh = 4;
    test->m_witdh = 7;
    test->map = copy_map(test);
    map_checker(test);
	return (0);
}
