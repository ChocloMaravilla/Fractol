/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 17:24:02 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_HEADER_H
# define FRACTOL_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "fractol_structs.h"
# include <math.h>

# define WIDTH 1000
# define HEIGHT	1000
# define NOT_IN_RANGE 2147483647
# define ITER 20
# define TURQUESA 0x03FC90
# define ROSE 0xFC036F
# define AZUL 0x0073e6
# define B_ESCAPE 65307
# define B_LEFT 65361
# define B_UP 65362
# define B_RIGHT 65363
# define B_DOWN 65364
# define B_PLUS 61
# define B_MINUS 45
# define B_A 97
# define B_W 119
# define B_D 100
# define B_S 115
# define B_CROSS 17
# define B_SCROLLUP 4
# define B_SCROLLDOWN 5
# define M_ERROR "Error few args: <./fractol mandelbrot>\
	or <./fractol julia 0.5 0.5>\n"
# define M_ERROR_1 "Error args invalid <./fractol julia arg1 arg2>\n"
# define M_ERROR_2 "Invalid arguments <.fractol julia 0.5 0.5>\n"

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			checking_type_of_set(char *str);
void		lower_case_converter(char *str);
int			checking_arg(int argc, char **argv);
int			ft_isalpha(int c);
size_t		ft_strlen(const char *c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			checking_symbols(char arg);
int			checking_next_char(char *str);
void		init_win(t_fract *win, t_img *img);
void		init_limits(t_fract *f);
int			iteration_to_scape(t_position c, t_position z, int iter);
double		ft_atod(char *num);
void		draw_mandelbrot(t_fract *vars);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			proportional_trgb(int percentage, int color, int max_color);
int			proportional_color(int percentage, int color, int max_color);
t_position	matrix_pos(t_pixel pos, t_screen screen);
t_position	position_in_square(t_pixel position, t_screen square);
void		malloc_err(void);
int			key_hook(int keycode, t_fract *fractal);
int			close_window(t_fract *fractal);
void		events_init(t_fract *fractal, t_img img);
void		movement_matrix(int key_code, t_fract *fractal);
void		zoom_matrix(int key_code, t_fract *fractal);
int			mouse_hook(int keycode, t_fract *fractal);
void		remaped(t_fract *fractal);
int			zoom_mouse_hook(int keycode, t_fract *fractal);
void		init_var(t_pixel *px, int count, t_fract *vars);
void		draw_julia(t_fract *vars);
double		get_decimals(char *num);
void		init_var_struct(t_fract *fractal, char **argv);
#endif
