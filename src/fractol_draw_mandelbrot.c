/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_mandelbrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:07:06 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 00:27:21 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int	proportional_color(int percentage, int color, int max_color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;
	int	nw_color;

	if (color == max_color)
		return (color);
	new_t = proportional_trgb(percentage,
			color >> 24 & 255, max_color >> 24 & 255);
	new_r = proportional_trgb(percentage,
			color >> 16 & 255, max_color >> 16 & 255);
	new_g = proportional_trgb(percentage,
			color >> 8 & 255, max_color >> 8 & 255);
	new_b = proportional_trgb(percentage,
			color & 255, max_color & 255);
	nw_color = new_t << 24 | new_r << 16 | new_g << 8 | new_b;
	return (nw_color);
}

int	iteration_to_scape(t_position c, t_position z, int iter)
{
	double	tmp;
	int		count;

	count = 0;
	if (sqrt(pow(c.real, 2) + pow(c.im, 2)) > 2)
		return (2147483647);
	while (count < iter)
	{
		if ((z.real > 2 || z.real < -2) || (z.im > 2 || z.im < -2))
			break ;
		tmp = (z.real * z.real) - (z.im * z.im);
		z.im = 2 * z.real * z.im;
		z.real = tmp;
		z.real = z.real + c.real;
		z.im = z.im + c.im;
		if (sqrt(pow(z.real, 2) + pow(z.im, 2)) > 2)
			break ;
		count++;
	}
	return (count);
}

int	proportional_trgb(int percentage, int color, int max_color)
{
	int	diff;

	diff = max_color - color;
	color = color + diff * percentage / 1000;
	return (color);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void		draw_mandelbrot(t_fract *vars)
{
	t_position	z;
	t_position	c;
	t_pixel	px;
	int		count;

	px.y = 0;
	px.x = 0;
	c = position_in_square(px, vars->matrix);
	while (px.y < HEIGHT)
	{
		px.x = 0;
		while (px.x < WIDTH)
		{
			c = position_in_square(px, vars->matrix);
			z.real = 0.0;
			z.im = 0.0;
				count = iteration_to_scape(c, z, vars->iter);
				if (count != 2147483647)
					px.color = proportional_color(
						count * 1000 / vars->iter, AZUL, TURQUESA);
				else
					px.color = AZUL;
				my_mlx_pixel_put(vars->img_ptr, px.x, px.y, px.color);
				px.x += 1;
			}
			px.y += 1;
		}
}
