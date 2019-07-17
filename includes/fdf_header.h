/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:44:52 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/14 12:44:38 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H

# include <mlx.h>
#include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libftprintf/includes/ft_printf.h"

# define S_COL 0x2F3561
# define E_COL 0xFFB961
# define L_COL 0xff0000
# define PI 3.1415926
# define RAD 3.1415926 / 180.0
# define WIDTH 1080
# define SHIFT 80
# define HEIGHT 1080
# define ANGLE_DELTA 1
# define NUM_7	89
# define NUM_8	91
# define NUM_9	92
# define NUM_4	86
# define NUM_6	88
# define NUM_2	84
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_fdf	t_fdf;
typedef struct s_dot	t_dot;
typedef struct s_links	t_links;
typedef struct s_vector	t_vector;
typedef struct s_button	t_button;
typedef struct s_print	t_print;
typedef t_dot	*(*t_rtc)(t_dot *dot, int angle);

struct			s_button
{
	int		help;
	int		button;
};

struct			s_print
{
	int		deltax;
	int		deltay;
	int		err;
	int		err2;
	int		diry;
	int		dirx;
};

struct			s_vector
{
	double		x;
	double		y;
	double		z;
};

struct			s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_addr;
	int			bits_pp;
	int			size_line;
	int			endian;
	int			width_d;
	int			height_d;
	int			fd;
	char		*file;
	t_vector	offset;
	t_vector	rad;
	t_button	button;
	t_print		pr;
	t_dot		***dots;
};


struct			s_dot
{
	t_vector	vec;
	int			color;
};



/*
**		main.c
*/
t_fdf			*init_node();
int				parce_map(t_fdf *fdf);
void			f_error(void);
void			free_arr(char **str);
void			init_window(t_fdf *fdf);
/*
**		map.c
*/
int				parce_map(t_fdf *fdf);
void			parce_map_size(t_fdf *fdf);
t_dot			*init_dot(int x, int y, int z);
t_dot			***create_dots_map(int w, int h);
int				count_ppl(t_fdf *fdf);
/*
**		debug.c
*/
void			print_map_debug(t_fdf *fdf);
/*
**		print.c
*/
void			print_manager(t_fdf *fdf);
void			print_map(t_fdf *fdf, int h, int w);
void			print_line(t_fdf *fdf, t_dot *start, t_dot *end);
void			print_dot(t_fdf *fdf, t_dot *dot);
void			print_help(t_fdf *fdf);
/*
**		hook.c
*/
int				keyb_conf(int key, void *param);
int				close_win(int key, void *param);
void			rotate_hook(t_fdf *fdf, int x, int y, int z);
void			offset_hook(t_fdf *fdf, int x, int y);
void			change_scale(t_fdf *fdf, int s);
/*
**		rotate.c
*/
void			rotate_map(t_fdf *fdf);
t_dot			*rotate(t_fdf *fdf, t_dot *dot);
/*
**		normalize.c
*/
void			normalize_vec(t_fdf *fdf, t_dot *start, t_dot *end);
t_dot			*normalize_dot(t_dot *dot, int pp_line, t_fdf *fdf);
t_dot			*normalize_to_cent(t_dot *dot, t_fdf *fdf);
/*
**		color.c
*/
int				set_color(int z);
int				get_color(t_fdf *fdf, t_dot *s, t_dot *e, t_dot *c);
int				get_light(int start, int end, double percent);
double			percent(int start, int end, int curr);

#endif