#include "includes/cube.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	init_data(argc, argv, data);
	map_checker(data);
	return (0);
}
