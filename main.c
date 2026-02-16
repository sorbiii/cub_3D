#include "includes/cube.h"

void init_mlx(t_data *data)
{
	data->mlx_info->mlx = mlx_init();
	if (!data->mlx_info->mlx)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->win = mlx_new_window(data->mlx_info->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!data->mlx_info->win)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->img = mlx_new_image(data->mlx_info->mlx, WIDTH, HEIGHT);
	if (!data->mlx_info->img)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->data_addr = mlx_get_data_addr(data->mlx_info->img,
			&data->mlx_info->bits_per_pixel, &data->mlx_info->line_size,
			&data->mlx_info->endian);
	if (!data->mlx_info->data_addr)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->converted_bits_x = data->mlx_info->bits_per_pixel / 8;
}

int main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	map_checker(data);
	math_init(data);
	init_mlx(data);
	render(data);
	return (0);
}

int	render(t_data *data)
{
	mlx_hook(data->mlx_info->win, 2, 1L<<0, handler, data);
	mlx_loop(data->mlx_info->mlx);
	return (0);
}

