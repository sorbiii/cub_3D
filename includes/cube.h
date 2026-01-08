/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/08 23:58:53 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

typedef enum error
{
    INCORECT_CHAR,
    MALLOC_ERROR,
    TOO_MANY_PLRS,
    MAP_ERROR,
}   error;

typedef struct s_data
{
    char **map;
    int     m_heigh;
    int     m_witdh;
}   t_data;

int	map_checker(t_data *data);
void	incorect_chars_checker(t_data *d, int y, int x, int count);
void	is_map_closed(char **m, int x, int y, int heigh);
#endif  