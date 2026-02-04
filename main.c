#include "includes/cube.h"

void init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_and_exit(MLX_ERROR, data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!data->win)
		error_and_exit(MLX_ERROR, data);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	map_checker(data);
	math_init(data);
	render(data);
	return (0);
}

int	render(t_data *data)
{
	init_mlx(data);
	mlx_hook(data->win, 2, 1L<<0, handler, data);
	mlx_loop(data->mlx);
}

int	handler(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)//W,A,S,D
	{
		move_handler(keycode, data);
		return (0);
	}
	if (keycode == 65361 || keycode == 65363)// left and right arrows
	{
		rotation_handler(keycode, data);
		return (0);	
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_everything(data);
		exit (0);
	}
	else
		return (0);
}

void	move_handler(int keycode, t_data *d)
{
	double	new_x;
	double	new_y;

	if (keycode == 119)
		move_up_and_down(&new_x, &new_y, UP, d);
	else if (keycode == 115)
		move_up_and_down(&new_x, &new_y, DOWN, d);
	else if (keycode == 97)
		move_right_and_left(&new_x, &new_y, LEFT, d);
	else if (keycode == 100)
		move_right_and_left(&new_x, &new_y, RIGHT, d);
	if (d->map[(int)new_y][(int)d->plr_x] != '1')
		d->plr_y = new_y;
	if (d->map[(int)d->plr_y][(int)new_x] != '1')	
			d->plr_x = new_x;
	return ;
}
void	move_up_and_down(double *x, double *y, int code, t_data *data)
{
	if (code == UP)
	{
		*x = data->plr_x + (data->p_dir_x * plr_speed);
		*y = data->plr_y + (data->p_dir_y * plr_speed);
		return ;
	}
	else if (code == DOWN)
	{
		*x = data->plr_x - (data->p_dir_x * plr_speed);
		*y = data->plr_y - (data->p_dir_y * plr_speed);
		return ;
	}
}

void	move_right_and_left(double *x, double *y, int code, t_data *data)
{
	if (code == RIGHT)
	{
		*x = data->plr_x - (data->p_dir_y * plr_speed);
		*y = data->plr_y + (data->p_dir_x * plr_speed);
		return ;
	}
	else if (code == LEFT)
	{
		*x = data->plr_x + (data->p_dir_y * plr_speed);
		*y = data->plr_y - (data->p_dir_x * plr_speed);
		return ;
	}
}

void rotation_handler(int keycode, t_data *data)
{
	if (keycode == 65361)//left
	{
		dir_and_plank_update(data, rot_speed);
	}
	else if (keycode == 65363)//right
	{
		dir_and_plank_update(data, -rot_speed);
	}
	return ;
}

void	math_init(t_data *data)
{
	data->p_dir_x = 0;
	data->p_dir_y = 0;
	if (data->plr_facing == 'N')
		data->p_dir_y = -1;
	else if (data->plr_facing == 'S')
		data->p_dir_y = 1;
	else if (data->plr_facing == 'E')
		data->p_dir_x = 1;
	else if (data->plr_facing == 'W')
		data->p_dir_x = -1;
	data->plane_x = -data->p_dir_y * 0.66;
	data->plane_y = data->p_dir_x * 0.66;
}

void	dir_and_plank_update(t_data *d, double rotspeed)
{
	double	old_plane_x;
	double	old_dir_x;
	double	cos_rot;
	double	sin_rot;

	old_dir_x = d->p_dir_x;
	old_plane_x = d->plane_x;
	cos_rot = cos(rotspeed);
	sin_rot = sin(rotspeed);

	d->p_dir_x = d->p_dir_x * cos_rot - d->p_dir_y * sin_rot;
	d->p_dir_y = old_dir_x * sin_rot + d->p_dir_y * cos_rot;

	d->plane_x = d->plane_x * cos_rot - d->plane_y * sin_rot;
	d->plane_y = old_plane_x *sin_rot + d->plane_y * cos_rot;
}
