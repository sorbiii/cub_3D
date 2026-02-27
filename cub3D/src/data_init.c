/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:18 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 14:27:19 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	null_struct(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->f_color = -1;
	data->c_color = -1;
}

void	init_mlx(t_data *data)
{
	data->mlx_info->mlx = mlx_init();
	if (!data->mlx_info->mlx)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->win = mlx_new_window(data->mlx_info->mlx,
			WIDTH, HEIGHT, "CUB3D");
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

void	math_init(t_data *data)
{
	data->mlx_info = calloc(1, sizeof(t_mlx));
	if (!data->mlx_info)
		error_and_exit(MALLOC_ERROR, data);
	data->plr_info->p_dir_x = 0;
	data->plr_info->p_dir_y = 0;
	if (data->plr_facing == 'N')
		data->plr_info->p_dir_y = -1;
	else if (data->plr_facing == 'S')
		data->plr_info->p_dir_y = 1;
	else if (data->plr_facing == 'E')
		data->plr_info->p_dir_x = 1;
	else if (data->plr_facing == 'W')
		data->plr_info->p_dir_x = -1;
	data->plr_info->plane_x = -data->plr_info->p_dir_y * 0.66;
	data->plr_info->plane_y = data->plr_info->p_dir_x * 0.66;
}

void	read_from_file(t_data *data, int fd)
{
	char	*line;
	char	*temp;
	char	*first_map_line;

	data->line_map = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = data->line_map;
		data->line_map = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	first_map_line = textures_colors_to_struct(data, &data->line_map);
	if (!first_map_line)
		error_and_exit(MAP_ERROR, data);
	data->map = convert_map(data, &data->line_map, first_map_line);
	add_spaces_to_map(data);
}

void	init_data(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		error_and_exit(WRONG_ARG_NUM, data);
	if (is_valid_extention(argv[1], ".cub", ft_strlen(".cub")) == -1)
		error_and_exit(WRONG_EXTENTION, data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_exit(FILE_OPEN_FAILURE, data);
	read_from_file(data, fd);
	close(fd);
}
