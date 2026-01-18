#include "includes/cube.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	map_checker(data);
	clean(data);
	return (0);
}
