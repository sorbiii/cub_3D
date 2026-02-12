#include "../includes/cube.h"

int ft_key_press(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_window(param);
	return (0);
}

int close_window(void *param)
{
	t_data *data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->img);
	mlx_destroy_window(data->mlx_info->mlx, data->mlx_info->win);
	mlx_destroy_display(data->mlx_info->mlx);
	free_everything(data);
	exit(0);
}
