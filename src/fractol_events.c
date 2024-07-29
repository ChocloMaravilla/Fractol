/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:37:29 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 03:29:40 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int key_hook(int keycode, t_fract *fractal)
{
	if(keycode == B_ESCAPE)
		close_window(fractal);
	else if(keycode == B_LEFT || keycode == B_A)
		movement_matrix(B_A, fractal);
	else if(keycode == B_RIGHT || keycode == B_D)
		movement_matrix(B_D, fractal);
	else if(keycode == B_UP || keycode == B_W)
		movement_matrix(B_W, fractal);
	else if(keycode == B_DOWN || keycode == B_S)
		movement_matrix(B_S, fractal);	
	else if(keycode == B_MINUS)
		zoom_matrix(B_MINUS, fractal);
	else if(keycode == B_PLUS)
		zoom_matrix(B_PLUS, fractal);
	else
		return (0);
	if(ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if(ft_strncmp(fractal->name, "julia", 5) == 0)
		printf("julia\n");
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, \
			fractal->img_ptr->img, 0, 0);
	return (0);
}

void movement_matrix(int key_code, t_fract *fractal)
{
	if(key_code == B_A)
	{
		fractal->matrix.im_x += 0.5f;
		fractal->matrix.fi_x += 0.5f;
	}
	else if(key_code == B_D)
	{
		fractal->matrix.im_x -= 0.5f;
		fractal->matrix.fi_x -= 0.5f;

	}
	else if(key_code == B_W)
	{
		fractal->matrix.im_y += 0.5f;
		fractal->matrix.fi_y += 0.5f;
	
	}
	else if(key_code == B_S)
	{
		fractal->matrix.im_y -= 0.5f;
		fractal->matrix.fi_y -= 0.5f;
	}
}

void zoom_matrix(int key_code, t_fract *fractal)
{
	if(key_code == B_MINUS)
	{
		fractal->matrix.im_x -= 0.2;
		fractal->matrix.fi_x += 0.2;
		fractal->matrix.im_y -= 0.2;
		fractal->matrix.fi_y += 0.2;
	}
	else if(key_code == B_PLUS)
	{
		fractal->matrix.im_x += 0.2;
		fractal->matrix.fi_x -= 0.2;
		fractal->matrix.im_y += 0.2;
		fractal->matrix.fi_y -= 0.2;
	}
}

int close_window(t_fract *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	exit(0);
	return (0);
}

int mouse_hook(int keycode, t_fract *fractal)
{
	static void *frac_dir;

	if (keycode == -2147483648)
	{
		frac_dir = fractal;
		return (0);
	}
	fractal = frac_dir;
	if(keycode == B_SCROLLUP)
	{
		/*return (key_hook(B_Plus, fractal));*/
		zoom_mouse_hook(B_PLUS, fractal);
	}
	if(keycode == B_SCROLLDOWN)
	{
		/*return (key_hook(B_Minus, fractal));*/
		zoom_mouse_hook(B_MINUS, fractal);
	}
	remaped(fractal);
	return (0);
}
