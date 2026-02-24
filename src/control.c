#include "../includes/cube.h"

int	ft_key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_window(param);
	return (0);
}

void	destroy_textures(t_data *data)
{
	if (data->mlx_info && data->mlx_info->mlx)
	{
		if (data->mlx_info->north.img)
			mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->north.img);
		if (data->mlx_info->south.img)
			mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->south.img);
		if (data->mlx_info->east.img)
			mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->east.img);
		if (data->mlx_info->west.img)
			mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->west.img);
	}
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data && data->mlx_info && data->mlx_info->mlx)
	{
		destroy_textures(data);
		if (data->mlx_info->img)
			mlx_destroy_image(data->mlx_info->mlx, data->mlx_info->img);
		if (data->mlx_info->win)
			mlx_destroy_window(data->mlx_info->mlx, data->mlx_info->win);
		mlx_destroy_display(data->mlx_info->mlx);
		free(data->mlx_info->mlx);
		data->mlx_info->mlx = NULL;
	}
	free(data->keys);
	free_everything(data);
	exit(0);
}
