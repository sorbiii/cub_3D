/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorbi <sorbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:55:54 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/16 15:30:25 by sorbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_put_pixel(int x, int y, int color, t_data *d)
{
	char	*dst;
	
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	dst = d->mlx_info->data_addr + (y * d->mlx_info->line_size) + (x * d->mlx_info->converted_bits_x);
	*(int*)dst = color;
	return ;
}
