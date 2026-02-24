#include "../includes/cube.h"

int	shade_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;

	if (factor < 0.2)
		factor = 0.2;
	if (factor > 1.0)
		factor = 1.0;
	r = (int)(((color >> 16) & 0xFF) * factor);
	g = (int)(((color >> 8) & 0xFF) * factor);
	b = (int)((color & 0xFF) * factor);
	return ((r << 16) | (g << 8) | b);
}

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
	double	distance;
	double	wall_height;
	double	shade_factor;
	int		b_wall_pixel;
	int		t_wall_pixel;
	int		wall_color;
	int		y;

	y = 0;
	distance = dda_init(rayX, rayY, d);
	if (distance <= 0.0001)
		distance = 0.0001;
	shade_factor = 1.0 / (1.0 + distance * 0.07);
	if (d->ray_info->side == 1)
		shade_factor *= 0.75;
	wall_color = shade_color(d->f_color, shade_factor);
	wall_height = HEIGHT / distance;
	b_wall_pixel = HEIGHT / 2 + wall_height / 2;
	t_wall_pixel = HEIGHT / 2 - wall_height / 2;
	if (t_wall_pixel < 0)
		t_wall_pixel = 0;
	if (b_wall_pixel >= HEIGHT)
		b_wall_pixel = HEIGHT - 1;
	while (y < HEIGHT)
	{
		if (y < t_wall_pixel)
			ft_put_pixel(x, y, 0xAAAAAA, d);
		else if (y < b_wall_pixel)
			ft_put_pixel(x, y, wall_color, d);
		else
			ft_put_pixel(x, y, d->c_color, d);
		y++;
	}
}
