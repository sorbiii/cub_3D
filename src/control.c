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
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_everything(data);
	//return (0); <- jak to jest to jest wiecej leakow?
	exit(0);
}

void mlx_control(t_data *data)
{
	mlx_key_hook(data->win, ft_key_press, data);
	mlx_hook(data->win, 17, 0L, close_window, data);
}