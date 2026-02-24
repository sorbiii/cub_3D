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

void load_textures(t_data *data)
{
	data->mlx_info->north.img = mlx_xpm_file_to_image(data->mlx_info->mlx,
		data->north_texture, &data->mlx_info->north.width, &data->mlx_info->north.height);
	if (!data->mlx_info->north.img)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->north.addr = mlx_get_data_addr(data->mlx_info->north.img,
		&data->mlx_info->north.bits_per_pixel, &data->mlx_info->north.line_size,
		&data->mlx_info->north.endian);
	
	data->mlx_info->south.img = mlx_xpm_file_to_image(data->mlx_info->mlx,
		data->south_texture, &data->mlx_info->south.width, &data->mlx_info->south.height);
	if (!data->mlx_info->south.img)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->south.addr = mlx_get_data_addr(data->mlx_info->south.img,
		&data->mlx_info->south.bits_per_pixel, &data->mlx_info->south.line_size,
		&data->mlx_info->south.endian);
	
	data->mlx_info->east.img = mlx_xpm_file_to_image(data->mlx_info->mlx,
		data->east_texture, &data->mlx_info->east.width, &data->mlx_info->east.height);
	if (!data->mlx_info->east.img)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->east.addr = mlx_get_data_addr(data->mlx_info->east.img,
		&data->mlx_info->east.bits_per_pixel, &data->mlx_info->east.line_size,
		&data->mlx_info->east.endian);
	
	data->mlx_info->west.img = mlx_xpm_file_to_image(data->mlx_info->mlx,
		data->west_texture, &data->mlx_info->west.width, &data->mlx_info->west.height);
	if (!data->mlx_info->west.img)
		error_and_exit(MLX_ERROR, data);
	data->mlx_info->west.addr = mlx_get_data_addr(data->mlx_info->west.img,
		&data->mlx_info->west.bits_per_pixel, &data->mlx_info->west.line_size,
		&data->mlx_info->west.endian);
}

int get_texture_color(t_data *d, t_ray *ray, int tex_y)
{
	t_texture	*tex;
	int			tex_x;
	char		*pixel;

	if (ray->side == 0 && ray->step_x > 0)
		tex = &d->mlx_info->east;
	else if (ray->side == 0 && ray->step_x < 0)
		tex = &d->mlx_info->west;
	else if (ray->side == 1 && ray->step_y > 0)
		tex = &d->mlx_info->south;
	else
		tex = &d->mlx_info->north;
	tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->step_x > 0) || (ray->side == 1 && ray->step_y < 0))
		tex_x = tex->width - tex_x - 1;
	pixel = tex->addr + (tex_y * tex->line_size + tex_x * (tex->bits_per_pixel / 8));
	return (*(int *)pixel);
}
