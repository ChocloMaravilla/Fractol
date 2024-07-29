/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hooks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 03:02:00 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 15:57:30 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int	zoom_mouse_hook(int keycode, t_fract *fractal)
{
	if (keycode == B_PLUS)
	{
		fractal->matrix.im_x -= 0.2f;
		fractal->matrix.fi_x += 0.2f;
		fractal->matrix.im_y -= 0.2f;
		fractal->matrix.fi_y += 0.2f;
	}
	else if (keycode == B_MINUS)
	{
		fractal->matrix.im_x += 0.2f;
		fractal->matrix.fi_x -= 0.2f;
		fractal->matrix.im_y += 0.2f;
		fractal->matrix.fi_y -= 0.2f;
	}
	return (0);
}

void	remaped(t_fract *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		draw_julia(fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img_ptr->img, 0, 0);
}
