#include "../includes/cube.h"

void	load_single_texture(t_data *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx_info->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		error_and_exit(WRONG_TEXTURE, data);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_size, &tex->endian);
}

void	load_textures(t_data *data)
{
	load_single_texture(data, &data->mlx_info->north, data->north_texture);
	load_single_texture(data, &data->mlx_info->south, data->south_texture);
	load_single_texture(data, &data->mlx_info->east, data->east_texture);
	load_single_texture(data, &data->mlx_info->west, data->west_texture);
}

t_texture	*select_texture(t_data *d, t_ray *ray)
{
	if (ray->side == 0 && ray->step_x > 0)
		return (&d->mlx_info->east);
	else if (ray->side == 0 && ray->step_x < 0)
		return (&d->mlx_info->west);
	else if (ray->side == 1 && ray->step_y > 0)
		return (&d->mlx_info->south);
	else
		return (&d->mlx_info->north);
}

int	calculate_tex_x(t_texture *tex, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int get_texture_color(t_data *d, t_ray *ray, int tex_y)
{
    t_texture   *tex;
    int         tex_x;
    char        *pixel;

    tex = select_texture(d, ray);
    tex_x = calculate_tex_x(tex, ray);
    
    // Zabezpieczenie zmiennej tex_x (oś pozioma tekstury)
    if (tex_x < 0)
        tex_x = 0;
    else if (tex_x >= tex->width)
        tex_x = tex->width - 1;
        
    // Zabezpieczenie zmiennej tex_y (oś pionowa tekstury)
    if (tex_y < 0)
        tex_y = 0;
    else if (tex_y >= tex->height)
        tex_y = tex->height - 1;

    pixel = tex->addr + (tex_y * tex->line_size + tex_x
            * (tex->bits_per_pixel / 8));
            
    return (*(int *)pixel);
}