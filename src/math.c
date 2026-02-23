#include "../includes/cube.h"

void dda_utils(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->plr_info->plr_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->plr_info->plr_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->plr_info->plr_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->plr_info->plr_y) * ray->delta_dist_y;
	}
}
void dda_loop(t_data *data, t_ray *ray)
{
	int hit;

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

void dda_algorithm(t_data *data, t_ray *ray)
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

double	dda_init(double rayX, double rayY, t_data *data)
{
	t_ray	ray;

	ray.ray_dir_x = rayX;
	ray.ray_dir_y = rayY;
	ray.map_x = (int)data->plr_info->plr_x;
	ray.map_y = (int)data->plr_info->plr_y;
	ray.side = 0;
	ray.perp_wall_dist = 0.0;
	dda_algorithm(data, &ray);
	if (data->ray_info)
		data->ray_info->side = ray.side;
	return (ray.perp_wall_dist);
}
