/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/11 15:03:49 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef enum error
{
	INCORECT_CHAR,
	MALLOC_ERROR,
	TOO_MANY_PLRS,
	MAP_ERROR,
}	error;

typedef struct s_data
{
	char	**map;
	int		m_heigh;
	int		m_witdh;
}	t_data;

int		map_close_helper(char **m, int y, int x);
int		is_valid(char c);
int		map_checker(t_data *data);
void	incorect_chars_checker(t_data *d, int y, int x, int count);
void	is_map_closed(char **m, int x, int y, int heigh);
void	error_and_exit(int i);
char	**copy_map(t_data *map);
int		is_valid_char(char c);
#endif