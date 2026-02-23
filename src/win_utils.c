/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorbi <sorbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:55:54 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/23 19:00:27 by sorbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_put_pixel(int x, int y, int color, t_data *d)
{
	char	*dst;
	
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = d->mlx_info->data_addr + (y * d->mlx_info->line_size) + (x * d->mlx_info->converted_bits_x);
	*(int*)dst = color;
	return ;
}
	
void	print_background(t_data *data)
{
	int i = 0;
	int j = 0;

	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_put_pixel(j, i, 0xFFFFFF, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_info->mlx, data->mlx_info->win, data->mlx_info->img , 0, 0);
	return ;
}