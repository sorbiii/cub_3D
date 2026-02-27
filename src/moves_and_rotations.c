/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_and_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:47 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/27 14:02:55 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	handler(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys->w = 1;
	else if (keycode == 97)
		data->keys->a = 1;
	else if (keycode == 115)
		data->keys->s = 1;
	else if (keycode == 100)
		data->keys->d = 1;
	else if (keycode == 65361)
		data->keys->left = 1;
	else if (keycode == 65363)
		data->keys->right = 1;
	else if (keycode == 65307)
		return (close_window(data));
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys->w = 0;
	else if (keycode == 97)
		data->keys->a = 0;
	else if (keycode == 115)
		data->keys->s = 0;
	else if (keycode == 100)
		data->keys->d = 0;
	else if (keycode == 65361)
		data->keys->left = 0;
	else if (keycode == 65363)
		data->keys->right = 0;
	return (0);
}

int	game_loop(t_data *data)
{
	if (data->keys->w)
		move_handler(119, data);
	if (data->keys->s)
		move_handler(115, data);
	if (data->keys->a)
		move_handler(97, data);
	if (data->keys->d)
		move_handler(100, data);
	if (data->keys->left)
		rotation_handler(65361, data);
	if (data->keys->right)
		rotation_handler(65363, data);
	render(data);
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
	if (d->map[(int)new_y][(int)d->plr_info->plr_x] != '1')
		d->plr_info->plr_y = new_y;
	if (d->map[(int)d->plr_info->plr_y][(int)new_x] != '1')
		d->plr_info->plr_x = new_x;
	return ;
}

void	rotation_handler(int keycode, t_data *data)
{
	if (keycode == 65361)
	{
		dir_and_plank_update(data, -ROT_SPEED);
	}
	else if (keycode == 65363)
	{
		dir_and_plank_update(data, ROT_SPEED);
	}
	return ;
}
