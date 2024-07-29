/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:01:57 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 14:09:34 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

void	events_init(t_fract *fractal, t_img img )
{
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, img.img, 0, 0);
	mlx_key_hook(fractal->win_ptr, key_hook, fractal);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, 17, 0L, close_window, fractal);
	mouse_hook(-2147483648, fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	malloc_err(void)
{
	write(1, "ERROR MALLOC\n", 13);
	exit(EXIT_FAILURE);
}

void	init_win(t_fract *win, t_img *img)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		malloc_err();
	win->win_ptr = mlx_new_window(win->mlx_ptr, HEIGHT, WIDTH, win->name);
	if (win->win_ptr == NULL)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		malloc_err();
	}
	img->img = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	if (img->img == NULL)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		malloc_err();
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	win->img_ptr = img;
	win->iter = ITER;
}

t_position	position_in_square(t_pixel position, t_screen square)
{
	t_position	scale;

	scale.real = (position.x - 0) * (square.fi_x - square.im_x) / (WIDTH - 0)
		+ square.im_x;
	scale.im = (position.y - 0) * (square.fi_y - square.im_y) / (HEIGHT - 0)
		+ square.im_y;
	return (scale);
}

void	init_limits(t_fract *f)
{
	f->matrix.im_x = -2;
	f->matrix.fi_x = 2;
	f->matrix.im_y = -2;
	f->matrix.fi_y = 2;
}
