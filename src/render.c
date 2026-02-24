/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:08:22 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/24 16:10:09 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	render(t_data *d)
{
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;

	x = 0;
	while (x < WIDTH)
	{
		camerax = 2.0 * x / (double)WIDTH - 1.0;
		raydirx = d->plr_info->p_dir_x + d->plr_info->plane_x * camerax;
		raydiry = d->plr_info->p_dir_y + d->plr_info->plane_y * camerax;
		dda_and_pixel_put(raydirx, raydiry, d, x);
		x++;
	}
	mlx_put_image_to_window(d->mlx_info->mlx, d->mlx_info->win,
		d->mlx_info->img, 0, 0);
	return (0);
}

static void	get_draw_range(double wall_height, int *draw_start, int *draw_end)
{
	*draw_start = -wall_height / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = wall_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
}

static void	draw_column_pixels(t_data *d, t_ray *ray, int x, int *range)
{
	int		y;
	double	wall_height;
	double	step;
	double	tex_pos;

	y = 0;
	wall_height = HEIGHT / ray->perp_wall_dist;
	step = 64.0 / wall_height;
	tex_pos = (range[0] - HEIGHT / 2 + wall_height / 2) * step;
	while (y < HEIGHT)
	{
		if (y < range[0])
			ft_put_pixel(x, y, d->c_color, d);
		else if (y <= range[1])
		{
			ft_put_pixel(x, y, get_texture_color(d, ray, (int)tex_pos % 64), d);
			tex_pos += step;
		}
		else
			ft_put_pixel(x, y, d->f_color, d);
		y++;
	}
}

void	dda_and_pixel_put(double rayX, double rayY, t_data *d, int x)
{
	t_ray	ray;
	double	wall_height;
	int		range[2];

	ray = dda_init(rayX, rayY, d);
	if (ray.perp_wall_dist <= 0.0001)
		ray.perp_wall_dist = 0.0001;
	wall_height = HEIGHT / ray.perp_wall_dist;
	get_draw_range(wall_height, &range[0], &range[1]);
	draw_column_pixels(d, &ray, x, range);
}
