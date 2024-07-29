/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:55:30 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/28 19:48:37 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

void		draw_julia(t_fract *vars, char *arg1, char *arg2)
{
	t_position	z;
	t_position	c;
	t_pixel	px;
	int		count;

	px.y = 0;
	while (px.y < HEIGHT)
	{
		px.x = 0;
		while (px.x < WIDTH)
		{
			z = position_in_square(px, vars->matrix);
			c.real = ft_atod(arg1);
			c.im = ft_atod(arg2);
			count = iteration_to_scape(c, z, vars->iter);
			if (count != 2147483647)
				px.color = proportional_color(
					count * 1000 / vars->iter, TURQUESA, ROSE);
			else
				px.color = TURQUESA;
			my_mlx_pixel_put(vars->img_ptr, px.x, px.y, px.color);
			px.x += 1;
		}
		px.y += 1;
	}
}
