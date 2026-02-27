/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:43:26 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/24 16:51:40 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	move_up_and_down(double *x, double *y, int code, t_data *data)
{
	if (code == UP)
	{
		*x = data->plr_info->plr_x + (data->plr_info->p_dir_x * PLR_SPEED);
		*y = data->plr_info->plr_y + (data->plr_info->p_dir_y * PLR_SPEED);
		return ;
	}
	else if (code == DOWN)
	{
		*x = data->plr_info->plr_x - (data->plr_info->p_dir_x * PLR_SPEED);
		*y = data->plr_info->plr_y - (data->plr_info->p_dir_y * PLR_SPEED);
		return ;
	}
}

void	move_right_and_left(double *x, double *y, int code, t_data *data)
{
	if (code == RIGHT)
	{
		*x = data->plr_info->plr_x - (data->plr_info->p_dir_y * PLR_SPEED);
		*y = data->plr_info->plr_y + (data->plr_info->p_dir_x * PLR_SPEED);
		return ;
	}
	else if (code == LEFT)
	{
		*x = data->plr_info->plr_x + (data->plr_info->p_dir_y * PLR_SPEED);
		*y = data->plr_info->plr_y - (data->plr_info->p_dir_x * PLR_SPEED);
		return ;
	}
}
