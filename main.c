/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:28:06 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 14:28:07 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	map_checker(data);
	math_init(data);
	init_mlx(data);
	load_textures(data);
	main_loop(data);
	return (0);
}

int	main_loop(t_data *data)
{
	render(data);
	data->ray_info = calloc(1, sizeof(t_ray));
	data->keys = calloc(1, sizeof(t_keys));
	if (!data->ray_info || !data->keys)
		error_and_exit(MALLOC_ERROR, data);
	mlx_hook(data->mlx_info->win, 2, 1L << 0, handler, data);
	mlx_hook(data->mlx_info->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_info->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_info->mlx, game_loop, data);
	mlx_loop(data->mlx_info->mlx);
	return (0);
}
