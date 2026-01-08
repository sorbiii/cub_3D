/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorbi <sorbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/08 23:01:28 by sorbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"

typedef enum error
{
    INCORRECT_CHAR,
    MALLOC_ERROR,
    WRONG_ARG_NUM,
    WRONG_EXTENTION,
}   error;

typedef struct s_data
{
    char    **map;
    int     m_heigh;
    int     m_witdh;
    char    plr_facing; //N, S, W, E
    int     plr_x;
    int     plr_y;
}   t_data;
#endif  