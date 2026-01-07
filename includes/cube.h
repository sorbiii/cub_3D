/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/07 20:56:29 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

typedef enum error
{
    INCORECT_CHAR,
    MALLOC_ERROR,
}   error;

typedef struct s_data
{
    char **map;
    int     m_heigh;
    int     m_witdh;
}   t_data;
#endif  