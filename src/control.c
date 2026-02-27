/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:09 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 16:22:40 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_everything(data);
	exit(0);
}
