/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:56:51 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/24 16:02:15 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	**copy_map(t_data *map)
{
	char	**mapcpy;
	int		i;

	i = 0;
	mapcpy = ft_calloc(map->m_height + 1, sizeof(char *));
	if (!mapcpy)
		return (NULL);
	while (i < map->m_height)
	{
		mapcpy[i] = ft_strdup(map->map[i]);
		if (!mapcpy[i])
		{
			while (--i >= 0)
				free(mapcpy[i]);
			free(mapcpy);
			return (NULL);
		}
		i++;
	}
	mapcpy[i] = NULL;
	return (mapcpy);
}

int	is_valid(char c)
{
	if (c != '0' && c != '1' && c != 'P')
		return (1);
	else
		return (0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || (c < 14 && c > 7))
		return (0);
	else if (c == 'S' || c == 'W' || c == 'E' || c == 'N')
		return (0);
	return (1);
}

void	dir_and_plank_update(t_data *d, double rotspeed)
{
	double	old_plane_x;
	double	old_dir_x;
	double	cos_rot;
	double	sin_rot;

	old_dir_x = d->plr_info->p_dir_x;
	old_plane_x = d->plr_info->plane_x;
	cos_rot = cos(rotspeed);
	sin_rot = sin(rotspeed);
	d->plr_info->p_dir_x = d->plr_info->p_dir_x
		* cos_rot - d->plr_info->p_dir_y * sin_rot;
	d->plr_info->p_dir_y = old_dir_x
		* sin_rot + d->plr_info->p_dir_y * cos_rot;
	d->plr_info->plane_x = d->plr_info->plane_x
		* cos_rot - d->plr_info->plane_y * sin_rot;
	d->plr_info->plane_y = old_plane_x
		* sin_rot + d->plr_info->plane_y * cos_rot;
}
