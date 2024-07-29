/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:10 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 17:26:51 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

int	invalid_arg(char *arg1)
{
	int	is_dot;
	int	i;

	i = 0;
	if (arg1[0] == '+' || arg1[0] == '-')
		i++;
	is_dot = 0;
	while ((arg1[i] >= '0' && arg1[i] <= '9')
		|| (is_dot == 0 && arg1[i] == '.'))
	{
		if (arg1[i] == '.')
		{
			is_dot = 1;
			if (arg1[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	if (arg1[i])
		return (1);
	return (0);
}

int	checking_arguments(int type, char **argv)
{
	if (type == 2)
	{
		if (!argv[2] || !argv[3])
		{
			write(1, M_ERROR_1, ft_strlen(M_ERROR_1));
			return (1);
		}
		if (invalid_arg(argv[2]) || invalid_arg(argv[3]))
		{
			write(1, M_ERROR_2, ft_strlen(M_ERROR_2));
			return (1);
		}
	}
	return (0);
}

int	checking_arg(int argc, char **argv)
{
	int	type_of_set;

	if (argv[1] == NULL)
	{
		write(1, M_ERROR, ft_strlen(M_ERROR));
		return (1);
	}
	lower_case_converter(argv[1]);
	type_of_set = checking_type_of_set(argv[1]);
	if (!type_of_set)
		return (1);
	if (checking_arguments(type_of_set, argv))
		return (1);
	else if (type_of_set == 3 && argc == 2)
		return (0);
	return (0);
}

void	init_var_struct(t_fract *fractal, char **argv)
{
	fractal->name = argv[1];
	fractal->button_x = 0.0f;
	fractal->button_y = 0.0f;
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->arg1 = ft_atod(argv[2]);
		fractal->arg2 = ft_atod(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fract	fractal;
	t_img	img;

	if (argc < 1)
	{
		write(1, M_ERROR, ft_strlen(M_ERROR));
		return (1);
	}
	if (checking_arg(argc, argv))
		exit(1);
	init_var_struct(&fractal, argv);
	init_limits(&fractal);
	init_win(&fractal, &img);
	if (checking_type_of_set(argv[1]) == 2)
		draw_julia(&fractal);
	else if (checking_type_of_set(argv[1]) == 3)
		draw_mandelbrot(&fractal);
	mlx_put_image_to_window(fractal.mlx_ptr, fractal.win_ptr, img.img, 0, 0);
	events_init(&fractal, img);
	return (0);
}
