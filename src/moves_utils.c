/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:43:26 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/12 15:44:00 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	move_up_and_down(double *x, double *y, int code, t_data *data)
{
	if (code == UP)
	{
		*x = data->plr_info->plr_x + (data->plr_info->p_dir_x * plr_speed);
		*y = data->plr_info->plr_y + (data->plr_info->p_dir_y * plr_speed);
		return ;
	}
	else if (code == DOWN)
	{
		*x = data->plr_info->plr_x - (data->plr_info->p_dir_x * plr_speed);
		*y = data->plr_info->plr_y - (data->plr_info->p_dir_y * plr_speed);
		return ;
	}
}

void	move_right_and_left(double *x, double *y, int code, t_data *data)
{
	if (code == RIGHT)
	{
		*x = data->plr_info->plr_x - (data->plr_info->p_dir_y * plr_speed);
		*y = data->plr_info->plr_y + (data->plr_info->p_dir_x * plr_speed);
		return ;
	}
	else if (code == LEFT)
	{
		*x = data->plr_info->plr_x + (data->plr_info->p_dir_y * plr_speed);
		*y = data->plr_info->plr_y - (data->plr_info->p_dir_x * plr_speed);
		return ;
	}
}
