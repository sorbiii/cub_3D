/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/01 19:31:52 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1600
# define HEIGHT 900

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
	WRONG_TEXTURE,
	MLX_ERROR,
	WRONG_RGB,
}   error;

typedef struct s_data
{
	char	**map;
	int		m_height;
	int		m_width;
	char	plr_facing; //N, S, W, E
	int		plr_x;
	int		plr_y;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		f_color;
	int		c_color;
	//mlx

	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_data;

// src/data_init.c
void	init_data(int argc, char **argv, t_data *data);
void	read_file(t_data *data, char *filename);
char	**create_map(t_data *data, int fd);
char	**map_convert(t_data *data, char **map);

// src/data_init_utils.c
char	*trim_spaces(const char *s);
void	null_struct(t_data *data);
void	check_texture_extention(t_data *data, char *s);
int		is_valid_extention(char *s, char *extention, int extention_len);
void	count_map_size(t_data *data, char **map, int start_idx);
int		ft_strcmp(const char *s1, const char *s2);
int		same_textures(t_data *data);
int		check_no_duplicates(char *s1, char *s2, char *s3, char *s4);

// src/extract_colors_textures.c
int		parse_rgb(t_data *data, char *s, int res, char *trimed);
void	colors_to_struct(t_data *data, char *line, int *num_of_elems, int *color);
void	textures_to_struct(t_data *data, char *line, int *num_of_elems, char **texture);
void	extract_utils(t_data *data, char *line, int *num_of_elems);
int		extract_textures_and_colors(t_data *data, char **map);

//src/control.c
int		close_window(void *param);
int		ft_key_press(int keycode, void *param);
void	mlx_control(t_data *data);

//src/error.c
void	error_and_exit(int i, t_data *data);
int		rgb_error(int r, int g, int b, char **nums);
int		rgb_connect_and_errors(char **nums, t_data *data);

//src/clean.c
void	free_map_rows(char **new_map, int count);
void	free_double_arr(char **arr);
char	*str_whitespace_cleaner(t_data *data, char *s, int i);
void	free_everything(t_data *data);

//src/map_checker.c
int		map_close_helper(char **m, int y, int x);
int		map_checker(t_data *data);
void	incorect_chars_checker(t_data *d, int y, int x, int count);
void	is_map_closed(t_data *data, char **m, int x, int y);

//src/utils.c
int		is_valid_char(char c);
char	**copy_map(t_data *map);
int		is_valid(char c);
#endif  


