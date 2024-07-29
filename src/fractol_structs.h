/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:54:37 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 14:52:06 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCTS_H 
# define FRACTOL_STRUCTS_H

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_screen
{
	float	im_x;
	float	fi_x;
	float	im_y;
	float	fi_y;
}	t_screen;

typedef struct s_position
{
	double	real;
	double	im;
}	t_position;

typedef struct s_fract
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img_ptr;
	int			iter;
	t_screen	matrix;
	t_position	c;
	t_position	z;
	float		real_julia;
	float		im_julia;
	double		button_x;
	double		button_y;
	double		arg1;
	double		arg2;
}	t_fract;	

/*my structs out of fractol*/
typedef struct s_var
{
	int	i;
	int	j;
}	t_var;
#endif
