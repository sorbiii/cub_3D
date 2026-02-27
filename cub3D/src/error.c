/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:12:29 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/27 16:33:56 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	rgb_error(int r, int g, int b, char **nums)
{
	int	i;

	i = 0;
	if (r > 255 || r < 0)
		return (1);
	if (g > 255 || g < 0)
		return (1);
	if (b > 255 || b < 0)
		return (1);
	while (i < 3)
	{
		if (nums[0][i] && (nums[0][i] > '9' || nums[0][i] < '0'))
			return (1);
		if (nums[1][i] && (nums[1][i] > '9' || nums[1][i] < '0'))
			return (1);
		if (nums[2][i] && (nums[2][i] > '9' || nums[2][i] < '0'))
			return (1);
		i++;
	}
	return (0);
}

void	error_and_exit(int i, t_data *data)
{
	free_everything(data);
	if (i == INCORRECT_CHAR)
		ft_putstr_fd("INCORRECT CHAR\n", 2);
	else if (i == MALLOC_ERROR)
		ft_putstr_fd("MALLOC ERROR\n", 2);
	else if (i == TOO_MANY_PLRS)
		ft_putstr_fd("WRONG AMOUNT OF PLAYERS\n", 2);
	else if (i == MAP_ERROR)
		ft_putstr_fd("MAP UNCLOSED\n", 2);
	else if (i == FILE_OPEN_FAILURE)
		ft_putstr_fd("ERROR WHILE OPENING FILE\n", 2);
	else if (i == WRONG_ARG_NUM)
		ft_putstr_fd("WRONG NUMBER OF ARGUMENTS\n", 2);
	else if (i == WRONG_EXTENTION)
		ft_putstr_fd("WRONG EXTENTION\n", 2);
	else if (i == WRONG_TEXTURE)
		ft_putstr_fd("SAME TEXTURES\n", 2);
	else if (i == WRONG_RGB)
		ft_putstr_fd("WRONG RGB\n", 2);
	else if (i == WRONG_TEXTURE_OR_COLOR)
		ft_putstr_fd("WRONG TEXTURE OR COLOR\n", 2);
	else if (i == MLX_ERROR)
		ft_putstr_fd("MLX ERROR\n", 2);
	exit(-1);
}

	int	rgb_connect_and_errors(char **nums, t_data *data, char *s, char **line)
{
	int	r;
	int	g;
	int	b;
	int	result;

	r = ft_atoi(nums[0]);
	g = ft_atoi(nums[1]);
	b = ft_atoi(nums[2]);
	if (rgb_error(r, g, b, nums))
	{
		free_double_arr(nums);
		free(*line);
		free(s);
		error_and_exit(WRONG_RGB, data);
	}
	result = (0 << 24) | (r << 16) | (g << 8) | (b);
	free_double_arr(nums);
	return (result);
}
