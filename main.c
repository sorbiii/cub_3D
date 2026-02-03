#include "includes/cube.h"

void init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_and_exit(MLX_ERROR, data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!data->win)
		error_and_exit(MLX_ERROR, data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		error_and_exit(MLX_ERROR, data);
	data->data_addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_size,
			&data->endian);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	//map_checker(data);
	free_everything(data);
	//init_mlx(data);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	//mlx_control(data);
	//mlx_loop(data->mlx);
	return (0);
}
