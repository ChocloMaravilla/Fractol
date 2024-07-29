/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:55:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 16:15:31 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int	iteration_to_scape_j(t_position c, t_position z, int iter)
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

void	draw_julia(t_fract *vars)
{
	t_position	z;
	t_position	c;
	t_pixel		px;
	int			count;

	px.y = 0;
	px.x = 0;
	z = position_in_square(px, vars->matrix);
	while (px.y < HEIGHT)
	{
		px.x = 0;
		while (px.x < WIDTH)
		{
			z = position_in_square(px, vars->matrix);
			c.real = vars->arg1;
			c.im = vars->arg2;
			count = iteration_to_scape_j(c, z, vars->iter);
			init_var(&px, count, vars);
			my_mlx_pixel_put(vars->img_ptr, px.x, px.y, px.color);
			px.x += 1;
		}
		px.y += 1;
	}
}
