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
	double	distance;
	double	wall_height;
	int		b_wall_pixel;
	int		t_wall_pixel;
	int		y;

	y = 0;
	distance = dda_init(rayX, rayY, d);
	if (distance <= 0.0001)
		distance = 0.0001;
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
			ft_put_pixel(x, y, d->f_color, d);
		else
			ft_put_pixel(x, y, d->c_color, d);
		y++;
	}
}
