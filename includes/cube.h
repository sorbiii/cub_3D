/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:48 by mzapora           #+#    #+#             */
/*   Updated: 2026/02/24 16:37:17 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1600
# define HEIGHT 900
# define ROT_SPEED 0.02
# define PLR_SPEED 0.02

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef enum directions
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_directions;

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
	WRONG_TEXTURE_OR_COLOR,
}	t_error;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_texture;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	int			converted_bits_x;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}	t_mlx;

typedef struct s_plr
{
	double		plr_x;
	double		plr_y;
	double		p_dir_x;
	double		p_dir_y;
	double		plane_x;
	double		plane_y;
}	t_plr;

typedef struct s_ray
{
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	int		side;
	double	perp_wall_dist;
	double	wall_x;
}	t_ray;

typedef struct s_data
{
	char		**map;
	char		*line_map;
	int			m_height;
	int			m_width;
	char		plr_facing; //N, S, W, E
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			f_color;
	int			c_color;
	t_plr		*plr_info;
	t_mlx		*mlx_info;
	t_ray		*ray_info;
	t_keys		*keys;
}	t_data;

// src/data_init.c
void		init_data(int argc, char **argv, t_data *data);
void		read_from_file(t_data *data, int fd);
void		null_struct(t_data *data);
void		math_init(t_data *data);
void		init_mlx(t_data *data);

//src/ma	p_parsing.c
int			is_blank_line(const char *s);
int			calculate_map_height(char **line, t_data *data);
char		*remove_first_line(char **src_line, int rest_len);
char		*extract_one_line(t_data *data, char **line);
char		*skip_blank_lines(t_data *data, char **line);

//src/ma	p_convert.c
char		**convert_map(t_data *data, char **big_line, char *first_map_line);
void		add_spaces_to_map(t_data *data);
void		fill_map_lines(t_data *data, char **big_line);
void		pad_map_lines(t_data *data, int max_w);
int			ft_strcmp(const char *s1, const char *s2);

// src/d	ata_init_utils.c
char		*trim_spaces(const char *s);
void		check_texture_extention(t_data *data, char *s, char **line);
int			is_valid_extention(char *s, char *extention, int extention_len);
int			same_textures(t_data *data);
int			check_no_duplicates(char *s1, char *s2, char *s3, char *s4);

// src/e	xtract_colors_textures.c
void		dispatch_element(t_data *data, char **line, int *num_of_elems);
void		extract(t_data *data, char **line, int *num_of_elems);
char		*get_next_non_blank_line(t_data *data, char **line);
char		*textures_colors_to_struct(t_data *data, char **line);

//src/te	xures_colors_utils.c
int			parse_rgb(t_data *data, char *s, int result, char **line);
void		colors_to_struct(t_data *data, char **line,
				int *num_of_elems, int *color);
void		textures_to_struct(t_data *data,
				char **line, int *num_of_elems, char **texture);

//src/co	ntrol.c
int			close_window(void *param);
int			ft_key_press(int keycode, void *param);
void		destroy_textures(t_data *data);

//src/er	ror.c
void		error_and_exit(int i, t_data *data);
int			rgb_error(int r, int g, int b, char **nums);
int			rgb_connect_and_errors(char **nums,
				t_data *data, char *s, char **line);

//src/cl	ean.c
void		free_map_rows(char **new_map, int count);
void		free_double_arr(char **arr);
char		*str_whitespace_cleaner(t_data *data, char *s, int i);
void		free_everything(t_data *data);

//src/ma	p_checker.c
int			map_close_helper(char **m, int y, int x, int height);
int			map_checker(t_data *data);
void		incorect_chars_checker(t_data *d, int y, int x, int count);
void		is_map_closed(t_data *data, char **m, int x, int y);
char		**copy_map(t_data *map);
int			is_valid_char(char c);
char		*str_whitespace_cleaner(t_data *data, char *s, int i);
void		free_double_arr(char **arr);
void		free_everything(t_data *data);
void		free_map_rows(char **new_map, int count);

//src/ut	ils.c
int			is_valid_char(char c);
char		**copy_map(t_data *map);
int			is_valid(char c);

//src/mo	ves_and_rotations.c
void		move_handler(int keycode, t_data *data);
int			handler(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
int			game_loop(t_data *data);
int			render(t_data *data);
void		rotation_handler(int keycode, t_data *data);
void		dir_and_plank_update(t_data *d, double rotspeed);

//src/mo	ves_utils.c
void		move_right_and_left(double *x, double *y, int code, t_data *data);
void		move_up_and_down(double *x, double *y, int code, t_data *data);

//src/wi	n_utils.c
void		ft_put_pixel(int x, int y, int color, t_data *d);
void		print_background(t_data *data);
void		dda_and_pixel_put(double rayX, double rayY, t_data *d, int x);
int			render(t_data *d);

//dda.c	
void		dda_utils(t_data *data, t_ray *ray);
void		dda_loop(t_data *data, t_ray *ray);
void		dda_algorithm(t_data *data, t_ray *ray);
t_ray		dda_init(double rayX, double rayY, t_data *data);

//src/ma	th.c
void		load_single_texture(t_data *data, t_texture *tex, char *path);
void		load_textures(t_data *data);
int			calculate_tex_x(t_texture *tex, t_ray *ray);
int			get_texture_color(t_data *d, t_ray *ray, int tex_y);
t_texture	*select_texture(t_data *d, t_ray *ray);

//main.c	
int			main_loop(t_data *data);

#endif
