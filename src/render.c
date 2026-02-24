#include "../includes/cube.h"

int	render(t_data *d)
{
	int 	x;
	double	cameraX;
	double	raydirX;
	double	raydirY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2.0 * x / (double)WIDTH - 1.0;
		raydirX = d->plr_info->p_dir_x + d->plr_info->plane_x * cameraX;
		raydirY = d->plr_info->p_dir_y + d->plr_info->plane_y * cameraX;
		dda_and_pixel_put(raydirX, raydirY, d, x);
		x++;
	}
	mlx_put_image_to_window(d->mlx_info->mlx, d->mlx_info->win,
		d->mlx_info->img, 0, 0);
	return (0);
}

void	dda_and_pixel_put(double rayX, double rayY, t_data *d, int x)
{
	t_ray	ray;
	double	wall_height;
	int		b_wall_pixel;
	int		t_wall_pixel;
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;

	y = 0;
	ray = dda_init(rayX, rayY, d);
	if (ray.perp_wall_dist <= 0.0001)
		ray.perp_wall_dist = 0.0001;
	wall_height = HEIGHT / ray.perp_wall_dist;
	draw_start = -wall_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	step = 1.0 * 64 / wall_height;
	tex_pos = (draw_start - HEIGHT / 2 + wall_height / 2) * step;
	while (y < HEIGHT)
	{
		if (y < draw_start)
			ft_put_pixel(x, y, d->c_color, d);
		else if (y <= draw_end)
		{
			tex_y = (int)tex_pos % 64;
			tex_pos += step;
			ft_put_pixel(x, y, get_texture_color(d, &ray, tex_y), d);
		}
		else
			ft_put_pixel(x, y, d->f_color, d);
		y++;
	}
}
