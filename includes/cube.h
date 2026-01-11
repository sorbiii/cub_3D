/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorbi <sorbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/11 15:37:49 by sorbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include "libft/libft.h"

typedef enum error
{

    INCORRECT_CHAR,
    MALLOC_ERROR,
    WRONG_ARG_NUM,
    WRONG_EXTENTION,
    FILE_OPEN_FAILURE,
    TOO_MANY_PLRS,
	MAP_ERROR,
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

// src/data_init.c
void init_data(int argc, char **argv, t_data *data);
void read_file(t_data *data, char *filename);
char **create_map(t_data *data, int fd);
char **map_create(t_data *data, char **map);
int is_valid_extention(char *s);


int		map_close_helper(char **m, int y, int x);
int		is_valid(char c);
int		map_checker(t_data *data);
void	incorect_chars_checker(t_data *d, int y, int x, int count);
void	is_map_closed(char **m, int x, int y, int heigh);
void	error_and_exit(int i);
char	**copy_map(t_data *map);
int		is_valid_char(char c);

#endif  


