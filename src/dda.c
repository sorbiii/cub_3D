/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadamczy <nadamczy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:27:23 by nadamczy          #+#    #+#             */
/*   Updated: 2026/02/27 16:42:59 by nadamczy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

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

void	dda_utils(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->plr_info->plr_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->plr_info->plr_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->plr_info->plr_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->plr_info->plr_y)
			* ray->delta_dist_y;
	}
}

void	dda_loop(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	dda_algorithm(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	dda_utils(data, ray);
	dda_loop(data, ray);
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

t_ray	dda_init(double rayX, double rayY, t_data *data)
{
	t_ray	ray;

	ray.ray_dir_x = rayX;
	ray.ray_dir_y = rayY;
	ray.map_x = (int)data->plr_info->plr_x;
	ray.map_y = (int)data->plr_info->plr_y;
	ray.side = 0;
	ray.perp_wall_dist = 0.0;
	dda_algorithm(data, &ray);
	if (ray.side == 0)
		ray.wall_x = data->plr_info->plr_y + ray.perp_wall_dist * ray.ray_dir_y;
	else
		ray.wall_x = data->plr_info->plr_x + ray.perp_wall_dist * ray.ray_dir_x;
	ray.wall_x -= floor(ray.wall_x);
	return (ray);
}
