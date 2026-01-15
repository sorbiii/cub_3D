/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/01/14 16:24:50 by mzapora          ###   ########.fr       */
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
    MAP_NOT_END,
}   error;

typedef struct s_data
{
    char    **map;
    int     m_heigh;
    int     m_witdh;
    char    plr_facing; //N, S, W, E
    int     plr_x;
    int     plr_y;
    char    *north_texture;
    char    *south_texture;
    char    *west_texture;
    char    *east_texture;
    int     f_color;
    int     c_color;
}   t_data;

// src/data_init.c
void init_data(int argc, char **argv, t_data *data);
void read_file(t_data *data, char *filename);
char **create_map(t_data *data, int fd);
char **map_convert(t_data *data, char **map);

// src/data_init_utils.c
char *trim_spaces(const char *s);
void null_struct(t_data *data);
void check_texture_extention(char *s);
int is_valid_map_extention(char *s, char *extention, int extention_len);
//zmienic na bez map^
void	count_map_size(t_data *data, char **map, int start_idx);

// src/extract_colors_textures.c
int parse_rgb(char *s, int i, int res, char *trimed);
void extract_colors_to_struct(char *line, int *num_of_elems, int *color);
void extract_textures_to_struct(char *line, int *num_of_elems, char **texture);
void extract_utils(t_data *data, char *line, int *num_of_elems);
int extract_textures_colors(t_data *data, char **map);


int		map_close_helper(char **m, int y, int x);
int		is_valid(char c);
int		map_checker(t_data *data);
void	incorect_chars_checker(t_data *d, int y, int x, int count);
void	is_map_closed(char **m, int x, int y, int heigh);
void	error_and_exit(int i);
char	**copy_map(t_data *map);
int		is_valid_char(char c);
void	clean_map_copy(char **map);
char	*str_whitespace_cleaner(char *s, int i);
void free_double_arr(char **arr);   


#endif  


